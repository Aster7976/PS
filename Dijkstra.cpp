ll n, start;
vector<pll> adj[n];
vector<ll> dist(n, INF);
vector<ll> pre(n);

void dijkstra()
{
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if(dist[cur.S] != cur.F)
            continue;

        for(auto next : adj[cur.S])
        {
            if(dist[next.S] <= dist[cur.S] + next.F)
                continue;

            dist[next.S] = dist[cur.S] + next.F;
            pre[next.S] = cur.S;
            pq.push({dist[next.S], next.S});
        }
    }
}
