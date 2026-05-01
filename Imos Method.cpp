ll n;
vector<ll> v(n);

void imos()
{
    while(n--)
    {
        ll l, r;
        cin >> l >> r;

        r++;
        
        v[l]++;
        v[r]--;
    }

    for(ll i = 2; i <= n; i++)
        v[i] += v[i - 1];
}
