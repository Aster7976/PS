ll n;
vector<vector<ll>> adj(n);
vector sp(n, vector<ll>(log n));
vector<ll> depth(n);

void dfs(ll cur)
{
    for(ll next : adj[cur])
        if(depth[next] == 0)
        {
            sp[next][0] = cur;
            depth[next] = depth[cur] + 1;
            dfs(next);
        }
}

void init()
{
    for(ll i = 1; i < log n; i++)
        for(ll j = 1; j < n; j++)
            if(sp[j][i - 1] != 0)
                sp[j][i] = sp[sp[j][i - 1]][i - 1];
}

ll lca(ll a, ll b)
{
    if(depth[a] < depth[b])
        swap(a, b);

    ll diff = depth[a] - depth[b];
    ll cur = 0;

    while(diff > 0)
    {
        if(diff % 2 == 1)
            a = sp[a][cur];

        diff /= 2;
        cur++;
    }

    if(a != b)
    {
        for(ll i = log n - 1; i >= 0; i--)
            if(sp[a][i] != 0 && sp[a][i] != sp[b][i])
            {
                a = sp[a][i];
                b = sp[b][i];
            }

        a = sp[a][0];
    }

    return a;
}
