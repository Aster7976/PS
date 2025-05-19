#include <bits/stdc++.h>

using namespace std;

void dfs(int start, vector<vector<int>> graph, vector<bool> visited)
{
    stack<int> s;
    s.push(start);

    while(s.empty() == false)
    {
        int temp = s.top();
        s.pop();

        if(visited[temp] == false)
        {
            visited[temp] = true;
            cout << temp << " ";

            for(int i = graph[temp].size() - 1; i >=0; i--)
            {
                int next = graph[temp][i];
                if(visited[next] == 0)
                    s.push(next);
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

    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n);

    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(v, graph, visited);

    return 0;
}