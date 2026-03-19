//BOJ 28018

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define F first
#define S second

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<int> imos(1000001);

    while(n--)
    {
        int l, r;
        cin >> l >> r;

        r++;
        
        imos[l]++;
        imos[r]--;
    }

    for(int i = 2; i <= 1000000; i++)
        imos[i] += imos[i - 1];

    int q;
    cin >> q;

    while(q--)
    {
        int t;
        cin >> t;

        cout << imos[t] << '\n';
    }
}
