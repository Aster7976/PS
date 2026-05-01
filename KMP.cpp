string s, p;
ll cnt;

vector<ll> failure(const string& x)
{
    vector<ll> f(x.size());

    ll j = 0;
    for(ll i = 1; i < x.size(); i++)
    {
        while(j > 0 && x[i] != x[j])
            j = f[j - 1];

        if(x[i] == x[j])
            f[i] = ++j;
    }

    return f;
}

void kmp()
{
    vector<ll> f = failure(p);
    ll j = 0;

    for(ll i = 0; i < s.size(); i++)
    {
        while(j > 0 && s[i] != p[j])
            j = f[j - 1];

        if(s[i] == p[j])
            j++;

        if(j == p.size())
            cnt++;
    }
}
