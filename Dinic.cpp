class Edge
{
public:
    ll to, rev, cap;
};

vector<vector<Edge>> edges(9);
vector<ll> level(9);
vector<ll> it(9);

void add(ll u, ll v, ll cap)
{
    edges[u].push_back({v, (ll)edges[v].size(), cap});
    edges[v].push_back({u, (ll)edges[u].size() - 1, 0});
}

bool bfs(ll src, ll sink)
{
    fill(level.begin(), level.end(), -1);
    queue<ll> q;
    level[src] = 0;
    q.push(src);

    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();

        for(Edge next : edges[cur])
        {
            if(next.cap > 0 && level[next.to] < 0)
            {
                level[next.to] = level[cur] + 1;
                q.push(next.to);
            }
        }
    }

    return level[sink] >= 0;
}

ll dfs(ll cur, ll sink, ll f)
{
    if(cur == sink)
        return f;

    for(ll& i = it[cur]; i < edges[cur].size(); i++)
    {
        Edge& next = edges[cur][i];

        if(next.cap > 0 && level[next.to] == level[cur] + 1)
        {
            ll d = dfs(next.to, sink, min(f, next.cap));

            if(d > 0)
            {
                next.cap -= d;
                edges[next.to][next.rev].cap += d;
                return d;
            }
        }
    }

    return 0;
}

ll mf(ll src, ll sink)
{
    ll flow = 0;

    while(bfs(src, sink))
    {
        fill(it.begin(), it.end(), 0);
        ll f;

        while((f = dfs(src, sink, INF)) > 0)
            flow += f;
    }

    return flow;
}
