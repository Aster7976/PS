#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << ' ';

        for(int i : graph[temp])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, v; // 정점의 개수, 간선의 개수, 시작 위치
    int a, b;
    cin >> n >> m >> v;

    graph.resize(n + 1);
    visited.resize(n + 1);

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(v);
}
