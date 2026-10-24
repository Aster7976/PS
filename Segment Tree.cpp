ll n;
vector<ll> v(n);
vector<ll> tree(4 * n);

ll query(ll cur, ll st, ll en, ll l, ll r)
{
    if(r < st || en < l)
        return 0;

    if(l <= st && en <= r)
        return tree[cur];

    ll m = (st + en) / 2;
    ll lsum = query(cur * 2, st, m, l, r);
    ll rsum = query(cur * 2 + 1, m + 1, en, l, r);
    return lsum + rsum;
}

void update(ll cur, ll st, ll en, ll idx)
{
    if(idx < st || en < idx)
        return;

    if(st == en)
    {
        tree[cur] = v[idx];
        return;
    }

    ll m = (st + en) / 2;
    update(cur * 2, st, m, idx);
    update(cur * 2 + 1, m + 1, en, idx);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}
