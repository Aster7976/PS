ll n;
vector<vector<ll>> adj(n);
vector<ll> depth(n);
vector sparse(n, vector<ll>(log n);

void lca()
{
    depth[1] = 1;

    for(auto next : adj[cur])
        if(depth[next] == 0)
        {
            sparse[next][0] = cur;
            depth[next] = depth[cur] + 1;
            init(next);
        }

    for(ll i = 1; i < log n; i++)
        for(ll j = 1; j <= n; j++)
            if(sparse[j][i - 1] != 0)
                sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];

    ll a, b;

    if(depth[a] < depth[b])
        swap(a, b);

    ll diff = depth[a] - depth[b];
    ll cur = 0;

    while(diff > 0)
    {
        if(diff % 2 == 1)   
            a = sparse[a][cur];
        
        diff /= 2;
        cur++;
    }

    if(a != b)
    {
        for(ll i = log n - 1; i >= 0; i--)
            if(sparse[a][i] != 0 && sparse[a][i] != sparse[b][i])
            {
                a = sparse[a][i];
                b = sparse[b][i];
            }

        a = sparse[a][0];
    }
}
