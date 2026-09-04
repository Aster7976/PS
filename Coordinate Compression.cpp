vector<ll> v1;
vector<ll> v2;
vector<ll> cc;

void coordinate_compression()
{
    v2 = v1;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for(auto i : v1)
        cc.push_back(lower_bound(v2.begin(), v2.end(), i) - v2.begin() + 1);
}
