// BOJ 1929

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define F first
#define S second

const int C = 1000001;

bool prime[C];

void init()
{
    for(int i = 2; i < C; i++)
        prime[i] = true;
}

void seive()
{
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

    init();
    seive();

    int m, n;
    cin >> m >> n;

    for(int i = m; i <= n; i++)
    {
        if(prime[i])
            cout << i << '\n';
    }
}
