ll n;
vector<vector<ll>> adj(n);
vector<ll> order(n);
vector<pll> bridge;
ll turn = 0;

ll dfs(ll cur, ll par)
{
    order[cur] = ++turn;
    ll low = order[cur];

    for(ll next : adj[cur])
    {
        if(next == par)
            continue;

        if(order[next])
        {
            low = min(low, order[next]);
            continue;
        }

        ll sub = dfs(next, cur);

        if(sub > order[cur])
            bridge.push_back({min(cur, next), max(cur, next)});
        
        low = min(low, sub);
    }

    return low;
}
