ll n;
vector<ll> v(n);
vector<ll> tree(4 * n);

void init(ll node, ll start, ll end)
{
    if(start == end)
	{
        tree[node] = v[start];
		return;
	}
	
	init(node * 2, start, (start + end) / 2);
	init(node * 2 + 1, (start + end) / 2 + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
