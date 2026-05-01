ll v, e, n;
tuple<ll, ll, ll> edge[n];
vector<ll> p(n, -1);

ll find(ll x)
{
    if(p[x] < 0)
        return x;

    return p[x] = find(p[x]);
}

bool uni(ll x, ll y)
{
    x = find(x);
    y = find(y);

    if(x == y)
        return false;

    p[y] = x;
    return true;
}

void mst()
{
    sort(edge, edge + e);

    ll cnt = 0;
    ll ans = 0;
    for(ll i = 0; i < e; i++)
    {
        ll a, b, cost;
        tie(cost, a, b) = edge[i];

        if(!uni(a, b))
            continue;

        ans += cost;
        cnt++;

        if(cnt == v - 1)
            break;
    }
}
