void ntt(vector<Mint>& a, bool inv)
{
    ll n = a.size();
    ll j = 0;

    for(ll i = 1; i < n; i++)
    {
        ll bit = n >> 1;

        while(j & bit)
        {
            j ^= bit;
            bit >>= 1;
        }

        j ^= bit;

        if(i < j)
            swap(a[i], a[j]);
    }

    for(ll len = 2; len <= n; len <<= 1)
    {
        Mint g = 3;
        Mint wlen = g.pow((MOD - 1) / len);

        if(inv)
            wlen = wlen.inv();

        for(ll i = 0; i < n; i += len)
        {
            Mint w = 1;

            for(ll k = 0; k < len / 2; k++)
            {
                Mint u = a[i + k];
                Mint v = a[i + k + len / 2] * w;
                a[i + k] = u + v;
                a[i + k + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(inv)
    {
        Mint ninv = n;
        ninv = ninv.inv();

        for(Mint& i : a)
            i *= ninv;
    }
}

vector<Mint> mul(const vector<Mint>& a, const vector<Mint>& b)
{
    if(a.empty() || b.empty())
        return {};

    vector<Mint> fa(a.begin(), a.end());
    vector<Mint> fb(b.begin(), b.end());
    ll n = 1;

    while(n < a.size() + b.size())
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);

    for(ll i = 0; i < n; i++)
        fa[i] *= fb[i];

    ntt(fa, true);

    fa.resize(a.size() + b.size() - 1);

    return fa;
}
