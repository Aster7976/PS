ll n;
vector<ll> v(n);
vector<ll> tree(4 * n);
vector<pll> mx(4 * n, {-INF, 1});
vector<pll> mn(4 * n, {INF, 1});

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

pll mxq(ll cur, ll st, ll en, ll l, ll r)
{
    if(r < st || en < l)
        return {-INF, 1};

    if(l <= st && en <= r)
        return mx[cur];

    ll m = (st + en) / 2;
    pll lmx = mxq(cur * 2, st, m, l, r);
    pll rmx = mxq(cur * 2 + 1, m + 1, en, l, r);
    return max(lmx, rmx);
}

pll mnq(ll cur, ll st, ll en, ll l, ll r)
{
    if(r < st || en < l)
        return {INF, 1};

    if(l <= st && en <= r)
        return mn[cur];

    ll m = (st + en) / 2;
    pll lmn = mnq(cur * 2, st, m, l, r);
    pll rmn = mnq(cur * 2 + 1, m + 1, en, l, r);
    return min(lmn, rmn);
}

void update(ll cur, ll st, ll en, ll idx)
{
    if(idx < st || en < idx)
        return;

    if(st == en)
    {
        tree[cur] = v[idx];
        mx[cur] = {v[idx], st};
        mn[cur] = {v[idx], st};
        return;
    }

    ll m = (st + en) / 2;
    update(cur * 2, st, m, idx);
    update(cur * 2 + 1, m + 1, en, idx);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    mx[cur] = max(mx[cur * 2], mx[cur * 2 + 1]);
    mn[cur] = min(mn[cur * 2], mn[cur * 2 + 1]);
}
