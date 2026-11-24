ll n;
vector<ll> seg(4 * n), lazy(8 * n);

void prop(ll cur, ll st, ll en)
{
    seg[cur] += lazy[cur] * (en - st + 1);
    lazy[cur * 2] += lazy[cur];
    lazy[cur * 2 + 1] += lazy[cur];
    lazy[cur] = 0;
}

ll query(ll cur, ll st, ll en, ll l, ll r)
{
    prop(cur, st, en);

    if(r < st || en < l)
        return 0;

    if(l <= st && en <= r)
        return seg[cur];

    ll m = (st + en) / 2;
    ll lseg = query(cur * 2, st, m, l, r);
    ll rseg = query(cur * 2 + 1, m + 1, en, l, r);
    return lseg + rseg;
}

void update(ll cur, ll st, ll en, ll l, ll r, ll val)
{
    prop(cur, st, en);

    if(r < st || en < l)
        return;

    if(l <= st && en <= r)
    {
        lazy[cur] += val;
        prop(cur, st, en);
        return;
    }

    ll m = (st + en) / 2;
    update(cur * 2, st, m, l, r, val);
    update(cur * 2 + 1, m + 1, en, l, r, val);
    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
}
