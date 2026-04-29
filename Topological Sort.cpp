vector<int> adj[32001];
vector<int> indegree(32001);
queue<int> q;

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
