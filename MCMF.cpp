class Edge
{
public:
    ll to, rev, cap, cost;
};

ll n;
vector<vector<Edge>> edges(n);
vector<ll> dist(n);
vector<ll> it(n);
vector<char> inq(n);
vector<char> vis(n);

void add(ll u, ll v, ll cap, ll cost)
{
    edges[u].push_back({v, (ll)edges[v].size(), cap, cost});
    edges[v].push_back({u, (ll)edges[u].size() - 1, 0, -cost});
}

bool spfa(ll src, ll sink)
{
    fill(dist.begin(), dist.end(), INF);
    fill(inq.begin(), inq.end(), false);
    queue<ll> q;
    dist[src] = 0;
    inq[src] = true;
    q.push(src);

    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        inq[cur] = false;

        for(Edge next : edges[cur])
        {
            if(next.cap <= 0)
                continue;

            if(dist[cur] + next.cost >= dist[next.to])
                continue;

            dist[next.to] = dist[cur] + next.cost;

            if(!inq[next.to])
            {
                inq[next.to] = true;
                q.push(next.to);
            }
        }
    }

    return dist[sink] < INF;
}

ll dfs(ll cur, ll sink, ll f)
{
    if(cur == sink)
        return f;

    vis[cur] = true;

    for(ll& i = it[cur]; i < edges[cur].size(); i++)
    {
        Edge& next = edges[cur][i];

        if(vis[next.to])
            continue;

        if(next.cap <= 0)
            continue;

        if(dist[next.to] != dist[cur] + next.cost)
            continue;

        ll d = dfs(next.to, sink, min(f, next.cap));

        if(d > 0)
        {
            next.cap -= d;
            edges[next.to][next.rev].cap += d;
            vis[cur] = false;
            return d;
        }
    }

    vis[cur] = false;
    return 0;
}

pll mcmf(ll src, ll sink)
{
    ll flow = 0;
    ll cost = 0;

    while(spfa(src, sink))
    {
        fill(it.begin(), it.end(), 0);
        ll f;

        while((f = dfs(src, sink, INF)) > 0)
        {
            flow += f;
            cost += f * dist[sink];
        }
    }

    return {flow, cost};
}
