ll n;
vector<ll> seg(n);

ll query(ll cur, ll st, ll en, ll l, ll r)
{
    if(r < st || en < l)
        return 0;

    if(l <= st && en <= r)
        return seg[cur];

    ll m = (st + en) / 2;
    ll lseg = query(cur * 2, st, m, l, r);
    ll rseg = query(cur * 2 + 1, m + 1, en, l, r);
    return lseg + rseg;
}

void update(ll cur, ll st, ll en, ll idx, ll val)
{
    if(idx < st || en < idx)
        return;

    if(st == en)
    {
        seg[cur] = val;
        return;
    }

    ll m = (st + en) / 2;
    update(cur * 2, st, m, idx, val);
    update(cur * 2 + 1, m + 1, en, idx, val);
    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
}
