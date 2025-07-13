#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int start)
{
    visited[start] = true;
    cout << start << ' ';

    for(int next : graph[start])
    {
        if(visited[next] == false)
            dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

    dfs(v);
}
