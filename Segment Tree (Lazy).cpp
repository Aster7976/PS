ll n;
vector<ll> v(n);
vector<ll> tree(4 * n);
vector<ll> lazy(4 * n);

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

void prop(ll cur, ll st, ll en)
{
    if(lazy[cur] == 0)
        return;

    tree[cur] += lazy[cur] * (en - st + 1);

    if(st != en)
    {
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2 + 1] += lazy[cur];
    }

    lazy[cur] = 0;
}

ll query(ll cur, ll st, ll en, ll l, ll r)
{
    prop(cur, st, en);

    if(r < st || en < l)
        return 0;

    if(l <= st && en <= r)
        return tree[cur];

    ll m = (st + en) / 2;
    ll lsum = query(cur * 2, st, m, l, r);
    ll rsum = query(cur * 2 + 1, m + 1, en, l, r);
    return lsum + rsum;
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
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}
