ll n;
vector<ll> v(n);
vector<ll> tree(4 * n);

void init(ll cur, ll st, ll en)
{
    if(st == en)
    {
        tree[cur] = v[st];
        return;
    }

    ll m = (st + en) / 2;
    init(cur * 2, st, m);
    init(cur * 2 + 1, m + 1, en);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

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

void update(ll cur, ll st, ll en, ll idx, ll val)
{
    if(idx < st || en < idx)
        return;

    if(st == en)
    {
        tree[cur] = val;
        v[st] = val;
        return;
    }

    ll m = (st + en) / 2;
    update(cur * 2, st, m, idx, val);
    update(cur * 2 + 1, m + 1, en, idx, val);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}
