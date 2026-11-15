void dijkstra()
{
    priority_queue<pll, vector<pll>, greater<>> pq;
    ll n, st;
    vector<vector<pll>> adj(n);
    vector<ll> dist(n, INF);

    dist[st] = 0;
    pq.push({dist[st], st});

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
