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

// v의 값 변경 - update(1, 1, n, in[v]);
// v의 서브트리 합 - query(1, 1, n, in[v], out[v]);
