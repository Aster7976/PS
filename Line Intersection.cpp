// BOJ 17387

#include <bits/stdc++.h>

using namespace std; 
using ll = long long;
using ld = long double;

#define F first
#define S second

vector<pair<ll, ll>> p(5);

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    ll cp = (b.F - a.F) * (c.S - a.S)
    - (b.S - a.S) * (c.F - a.F);

    if(cp > 0)
        return 1;
    else if(cp < 0)
        return -1;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 4; i++)
        cin >> p[i].F >> p[i].S;

    int c1 = ccw(p[1], p[2], p[3]) * ccw(p[1], p[2], p[4]);
    int c2 = ccw(p[3], p[4], p[1]) * ccw(p[3], p[4], p[2]);

    if(c1 == 0 && c2 == 0)
    {
        if(p[1] > p[2])
            swap(p[1], p[2]);
        if(p[3] > p[4])
            swap(p[3], p[4]);

        cout << (p[2] >= p[3] && p[4] >= p[1]);
    }
    else
        cout << (c1 <= 0 && c2 <= 0);
}
