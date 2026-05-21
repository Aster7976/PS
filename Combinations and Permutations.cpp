vector<mint> fact(n);
vector<mint> ifact(n);

void init()
{
    fact[0] = 1;

    for(ll i = 1; i < n; i++)
        fact[i] = fact[i - 1] * i;

    ifact[n - 1] = fact[n - 1].inv();

    for(ll i = n - 2; i >= 0; i--)
        ifact[i] = ifact[i + 1] * (i + 1);
}

mint nCr(ll x, ll y)
{
    return fact[x] * ifact[y] * ifact[x - y];
}

mint nPr(ll x, ll y)
{
    return fact[x] * ifact[x - y];
}

mint nHr(ll x, ll y)
{
    return nCr(x + y - 1, y);
}

mint nPIr(mint x, ll y)
{
    return x.pow(y);
}
