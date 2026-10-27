class Edge
{
public:
    ll to, rev, cap;
};

ll n;
vector<vector<Edge>> edges(n);
vector<ll> level(n);
vector<ll> it(n);

void add(ll u, ll v, ll cap)
{
    edges[u].push_back({v, (ll)edges[v].size(), cap});
    edges[v].push_back({u, (ll)edges[u].size() - 1, 0});
}

bool bfs(ll s, ll t) // s = source, t = sink
{
    fill(level.begin(), level.end(), -1);
    queue<ll> q;
    level[s] = 0;
    q.push(s);

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

    return level[t] >= 0;
}

ll dfs(ll cur, ll t, ll f)
{
    if(cur == t)
        return f;

    for(ll& i = it[cur]; i < edges[cur].size(); i++)
    {
        Edge& next = edges[cur][i];

        if(next.cap > 0 && level[next.to] == level[cur] + 1)
        {
            ll d = dfs(next.to, t, min(f, next.cap));

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

ll mf(ll s, ll t)
{
    ll flow = 0;

    while(bfs(s, t))
    {
        fill(it.begin(), it.end(), 0);
        ll f;

        while((f = dfs(s, t, INF)) > 0)
            flow += f;
    }

    return flow;
}
