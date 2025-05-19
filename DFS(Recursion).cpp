#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<vector<int>> graph, vector<bool> visited)
{
    visited[start] = true;
    cout << start << ' ';
    for(int next : graph[start])
    {
        if(visited[next] == false)
            dfs(next, graph, visited);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, v; // 정점의 개수, 간선의 개수, 시작 위치
    int a, b;
    cin >> n >> m >> v;

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n);

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(v, graph, visited);
}