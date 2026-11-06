ll n;
vector<vector<ll>> adj(n);
vector<ll> in(n);
vector<ll> out(n);
ll turn = 0;

void dfs(ll cur)
{
    in[cur] = ++turn;

    for(ll next : adj[cur])
        dfs(next);

    out[cur] = turn;
}

// change x - update(1, 1, n, in[x]);
// sum of subtree(x) - query(1, 1, n, in[x], out[x]);
