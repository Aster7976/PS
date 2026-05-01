ll n;
vector<ll> adj[32001];
vector<ll> indegree(32001);
queue<ll> q;

void ts()
{
    for(ll i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(ll next : adj[cur])
        {
            indegree[next]--;
            if(indegree[next] == 0)
                q.push(next);
        }
    }
}
