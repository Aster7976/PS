// BOJ 17387

#include <bits/stdc++.h>

using namespace std; 
using ll = long long;

#define F first
#define S second

vector<pair<ll, ll>> p(5);

int ccw(int a, int b, int c)
{
    ll cp = (p[b].F - p[a].F) * (p[c].S - p[a].S)
    - (p[b].S - p[a].S) * (p[c].F - p[a].F);

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

    int c1 = ccw(1, 2, 3) * ccw(1, 2, 4);
    int c2 = ccw(3, 4, 1) * ccw(3, 4, 2);

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
