// BOJ 2042

#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
vector<long long> tree;

void init(int node, int start, int end)
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

long long query(int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
        return 0;
    if(left <= start && end <= right)
        return tree[node];
    
    long long lsum = query(node * 2, start, (start + end) / 2, left, right);
    long long rsum = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return lsum + rsum;
}

void update(int node, int start, int end, int idx, long long val)
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

    int n, m, k;
    cin >> n >> m >> k;

    v = vector<long long>(n);
    int h = int(ceil(log2(n)));
    int size = pow(2, (h + 1));
    tree = vector<long long>(size);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    init(1, 0, n - 1);

    m += k;
    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int idx;
            long long val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx - 1, val);
        }
        else
        {
            int left, right;
            cin >> left >> right;
            cout << query(1, 0, n - 1, left - 1, right - 1) << '\n';
        }
    }
}
