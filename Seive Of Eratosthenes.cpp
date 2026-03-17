// BOJ 1929

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define F first
#define S second

const int C = 1000001;

vector<char> prime(C, true);

void seive()
{
    prime[1] = false;

    for(int i = 2; i * i < C; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j < C; j += i)
                prime[j] = false;
        }
    }   
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();

    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++)
    {
        if(prime[i])
            cout << i << '\n';
    }
}
