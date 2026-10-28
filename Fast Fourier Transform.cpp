const double pi = acos(-1);

void fft(vector<complex<double>>& a, bool inv)
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
        double ang = 2 * pi / len;
        if(inv)
            ang = -ang;
        complex<double> wlen = {cos(ang), sin(ang)};

        for(ll i = 0; i < n; i += len)
        {
            complex<double> w(1);

            for(ll j = 0; j < len / 2; j++)
            {
                complex<double> u = a[i + j];
                complex<double> v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if(inv)
        for(auto& i : a)
            i /= n;
}

vector<ll> mul(const vector<ll>& a, const vector<ll>& b)
{
    if(a.empty() || b.empty())
        return {};

    vector<complex<double>> fa(a.begin(), a.end());
    vector<complex<double>> fb(b.begin(), b.end());
    ll n = 1;

    while(n < a.size() + b.size())
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(ll i = 0; i < n; i++)
        fa[i] *= fb[i];

    fft(fa, true);

    vector<ll> res(a.size() + b.size() - 1);

    for(ll i = 0; i < res.size(); i++)
        res[i] = llround(fa[i].real());

    return res;
}
