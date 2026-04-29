int v, e, start;
vector<pair<int, int>> adj[20001];
vector<int> dist(20001, INF);

void dijkstra()
{
    priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

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
            pq.push({dist[next.S], next.S});
        }
    }
}
