ll n;
vector<ll> adj[n];
vector<ll> sz(n);
vector<char> vis(n);
ll cent = -1;

void fc(ll cur)
{
    sz[cur] = 1;
    ll mx = 0;
    vis[cur] = true;

    for(ll next : adj[cur])
    {
        if(vis[next])
            continue;

        fc(next);
        sz[cur] += sz[next];
        mx = max(mx, sz[next]);
    }

    mx = max(mx, n - sz[cur]);

    if(mx <= n / 2 && cent == -1)
        cent = cur;
}
