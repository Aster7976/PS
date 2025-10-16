// BOJ 2042

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> v;
vector<ll> tree;

void init(ll node, ll start, ll end)
{
    if(start == end)
        tree[node] = v[start];
    else
    {
        init(node * 2, start, (start + end) / 2);
        init(node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll query(ll node, ll start, ll end, ll left, ll right)
{
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    
    ll lsum = query(node * 2, start, (start + end) / 2, left, right);
    ll rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

void update(ll node, ll start, ll end, ll idx, ll val)
{
    if(idx < start || idx > end)
        return;
    if(start == end)
    {
        v[idx] = val;
        tree[node] = val;
        return;
    }

    update(node * 2, start, (start + end) / 2, idx, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    v = vector<ll>(n);
    ll h = ll(ceil(log2(n)));
    ll size = pow(2, (h + 1));
    tree = vector<ll>(size);

    for(ll i = 0; i < n; i++)
        cin >> v[i];

    init(1, 0, n - 1);

    m += k;
    while(m--)
    {
        ll op;
        cin >> op;
        if(op == 1)
        {
            ll idx;
            ll val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx - 1, val);
        }
        else
        {
            ll left, right;
            cin >> left >> right;
            cout << query(1, 0, n - 1, left - 1, right - 1) << '\n';
        }
    }
}
