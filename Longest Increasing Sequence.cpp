//BOJ 12738

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(i == 0)
        {
            v.push_back(x);
            continue;
        }

        if(x > v.back())
            v.push_back(x);
        else
        {
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[idx] = x;
        }
    } 

    cout << v.size();
}
