ll n;
vector<ll> sz(n);
vector<ll> depth(n);
vector<ll> par(n);
vector<ll> top(n);
vector<ll> in(n);
vector<ll> out(n);
vector<vector<ll>> adj(n);

void dfs1(ll cur)
{
    sz[cur] = 1;

    for(ll& next : adj[cur])
    {
        depth[next] = depth[cur] + 1;
        par[next] = cur;

        dfs1(next);

        sz[cur] += sz[next];
        if(sz[next] > sz[adj[cur][0]])
            swap(next, adj[cur][0]);
    }
}

ll turn = 0;

void dfs2(ll cur)
{
    in[cur] = ++turn;

    for(ll next : adj[cur])
    {
        if(next == adj[cur][0])
            top[next] = top[cur];
        else
            top[next] = next;

        dfs2(next);
    }

    out[cur] = turn;
}

ll hldq(ll a, ll b)
{
    ll ret = 0;

    while(top[a] != top[b])
    {
        if(depth[top[a]] < depth[top[b]])
            swap(a, b);

        ll st = top[a];
        ret += query(1, 1, n, in[st], in[a]);
        a = par[st];
    }

    if(depth[a] > depth[b])
        swap(a, b);

    ret += query(1, 1, n, in[a], in[b]);
    return ret;
}

// 노드 x의 값을 변경
// v[in[x]] = val;
// update(1, 1, n, in[x]);
