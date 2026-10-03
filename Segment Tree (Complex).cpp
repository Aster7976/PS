ll n;
vector<ll> v(n);
vector<ll> tree(4 * n);
vector<pll> mx(4 * n, {-INF, 1});
vector<pll> mn(4 * n, {INF, 1});

void init(ll cur, ll st, ll en)
{
    if(st == en)
    {
        tree[cur] = v[st];
        mx[cur] = {v[st], st};
        mn[cur] = {v[st], st};
        return;
    }

    ll m = (st + en) / 2;
    init(cur * 2, st, m);
    init(cur * 2 + 1, m + 1, en);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    mx[cur] = max(mx[cur * 2], mx[cur * 2 + 1]);
    mn[cur] = min(mn[cur * 2], mn[cur * 2 + 1]);
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

void update(ll cur, ll st, ll en, ll idx, ll val)
{
    if(idx < st || en < idx)
        return;

    if(st == en)
    {
        tree[cur] = val;
        mx[cur] = {val, st};
        mn[cur] = {val, st};
        v[st] = val;
        return;
    }

    ll m = (st + en) / 2;
    update(cur * 2, st, m, idx, val);
    update(cur * 2 + 1, m + 1, en, idx, val);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
    mx[cur] = max(mx[cur * 2], mx[cur * 2 + 1]);
    mn[cur] = min(mn[cur * 2], mn[cur * 2 + 1]);
}
