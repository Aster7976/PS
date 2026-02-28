// BOJ 1708

#include <bits/stdc++.h>

using namespace std; 
using ll = long long;
using ld = long double;

#define F first
#define S second

vector<pair<ll, ll>> p;

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

ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return (a.F - b.F) * (a.F - b.F)
    + (a.S - b.S) * (a.S - b.S);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    int c = ccw(p[0], a, b);

    if(c == 0)
        return dist(p[0], a) < dist(p[0], b);
    
    return c > 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    p.resize(n);
    vector<int> st(n);

    for(int i = 0; i < n; i++)
        cin >> p[i].F >> p[i].S;

    sort(p.begin(), p.end());
    sort(p.begin() + 1, p.end(), cmp);

    st[0] = 0;
    st[1] = 1;
    int top = 2;

    for(int i = 2; i < n; i++)
    {
        while(top >= 2 && ccw(p[st[top - 2]], p[st[top - 1]], p[i]) <= 0)
            top--;
        
        st[top] = i;
        top++;
    }

    cout << top;
}
