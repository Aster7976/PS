// BOJ 1717

#include <bits/stdc++.h>

using namespace std;

vector<int> p(1000001, -1);

int find(int x)
{
    if(p[x] < 0)
        return x;
    p[x] = find(p[x]);
    return find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)
        return false;
    p[v] = u;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if(op == 0)
            uni(a, b);
        else
        {
            if(find(a) == find(b))  
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
