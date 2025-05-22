#include <bits/stdc++.h>

using namespace std;

int v, e, start;
vector<pair<int, int>> adj[20001];
const int inf = 1e9;
int d[20001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e >> start;
    fill(d, d + v + 1, inf);
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<pair<int, int>, 
    vector<pair<int, int>>, 
    greater<pair<int, int>>> pq;
    d[start] = 0;

    pq.push({d[start], start});
    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if(d[temp.second] != temp.first)
            continue;
        for(auto next : adj[temp.second])
        {
            if(d[next.second] <= d[temp.second] + next.first)
                continue;
            d[next.second] = d[temp.second] + next.first;
            pq.push({d[next.second], next.second});
        }
    }
    for(int i = 1; i <= v; i++)
    {
        if(d[i] == inf)
            cout << "INF\n";
        else
            cout << d[i] << '\n';
    }
}