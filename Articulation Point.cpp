ll n;
vector<vector<ll>> adj(n);
vector<ll> order(n);
vector<char> cut(n);
ll turn = 0;

ll dfs(ll cur, bool root)
{
    order[cur] = ++turn;
    ll low = order[cur];
    ll child = 0;

    for(ll next : adj[cur])
    {
        if(order[next])
        {
            low = min(low, order[next]);
            continue;
        }

        child++;
        ll sub = dfs(next, false);

        if(!root && sub >= order[cur])
            cut[cur] = true;

        low = min(low, sub);
    }

    if(root && child >= 2)
        cut[cur] = true;

    return low;
}
