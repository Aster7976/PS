// BOJ 1197

#include <bits/stdc++.h>

using namespace std;

int v, e;
tuple<int, int, int> edge[100001];
vector<int> p(10001, -1);

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

    cin >> v >> e;
    for(int i = 0; i < e; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    
    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++)
    {
        int a, b, cost;
        tie(cost, a, b) = edge[i];

        if(!uni(a, b))
            continue;

        ans += cost;
        cnt++;

        if(cnt == v - 1)
            break;
    }

    cout << ans;
}
