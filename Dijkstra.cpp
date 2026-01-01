// BOJ 1753

// O(E log E)

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int v, e, start;
vector<pair<int, int>> adj[20001];
vector<int> dist(20001, INF);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> start;

    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        // first 거리
        // second 정점 번호

        if(dist[cur.second] != cur.first)
            continue;

        for(auto next : adj[cur.second])
        {
            if(dist[next.second] <= dist[cur.second] + next.first)
                continue;

            dist[next.second] = dist[cur.second] + next.first;
            pq.push({dist[next.second], next.second});
        }
    }

    for(int i = 1; i <= v; i++)
    {
        if(dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
}
