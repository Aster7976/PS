void dijkstra()
{
    ll n;
    vector<vector<pll>> adj(n);
    vector<ll> dist(n, INF);
    priority_queue<pll, vector<pll>, greater<>> pq;

    dist[1] = 0;
    pq.push({dist[1], 1});

    while(!pq.empty())
    {
        pll cur = pq.top();
        pq.pop();

        if(dist[cur.S] != cur.F)
            continue;

        for(pll next : adj[cur.S])
        {
            if(dist[next.S] <= dist[cur.S] + next.F)
                continue;

            dist[next.S] = dist[cur.S] + next.F;
            pq.push({dist[next.S], next.S});
        }
    }
}
