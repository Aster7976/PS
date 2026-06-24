void lis()
{
    vector<ll> v;
    ll n;
    cin >> n;

    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        if(i == 0)
        {
            v.push_back(x);
            continue;
        }

        if(x > v.back())
            v.push_back(x);
        else
        {
            ll idx = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[idx] = x;
        }
    } 
}
