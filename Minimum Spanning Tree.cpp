ll v, e, n;
vector<vector<ll>> edge; // cost, a, b
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
    sort(edge.begin(), edge.end());

    ll cnt = 0;
    ll ans = 0;
    for(ll i = 0; i < e; i++)
    {
        if(!uni(edge[i][1], edge[i][2]))
            continue;

        ans += edge[i][0];
        cnt++;

        if(cnt == v - 1)
            break;
    }
}
