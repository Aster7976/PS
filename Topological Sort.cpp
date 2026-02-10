// BOJ 2252

#include <bits/stdc++.h>

using namespace std;

vector<int> adj[32001];
vector<int> indegree(32001);
queue<int> q;
int n, m;

void ts()
{

    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int next : adj[cur])
        {
            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
        indegree[b]++;
    }

    ts();
}
