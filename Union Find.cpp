ll n;
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
