// BOJ 14003

#include <bits/stdc++.h>

using namespace std; 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> origin;
    vector<int> v;
    vector<int> idx(n);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        origin.push_back(x);

        if(i == 0 || x > v.back())
        {
            v.push_back(x);
            idx[i] = v.size() - 1;
        }    
        else
        {
            int temp = lower_bound(v.begin(), v.end(), x) - v.begin();
            v[temp] = x;
            idx[i] = temp;
        }
    }

    cout << v.size() << '\n';
    
    vector<int> ans;
    int len = v.size() - 1;
    for(int i = n - 1; i >= 0; i--)
    {
        if(idx[i] == len)  
        {
            ans.push_back(origin[i]);
            len--;
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << ' ';
}
