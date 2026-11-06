ll n;
vector<ll> v(n);
vector<ll> lis;

void f()
{
    for(ll i = 0; i < n; i++)
    {
        if(lis.empty() || v[i] > lis.back())
            lis.push_back(v[i]);
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    } 
}
