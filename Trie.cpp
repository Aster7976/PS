#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define F first
#define S second

const ll INF = 2e18;

ll n, len, letter;
vector<char> chk(n * len);
vector nxt(n * len, vector<ll>(letter, -1));
ll cnt = 1;

void insert(string s)
{
    ll cur = 0;

    for(char i : s)
    {
        if(nxt[cur][i - 'a'] == -1)
            nxt[cur][i - 'a'] = cnt++;

        cur = nxt[cur][i - 'a'];
    }

    chk[cur] = true;
}

bool find(string s)
{
    ll cur = 0;

    for(char i : s)
    {
        if(nxt[cur][i - 'a'] == -1)
            return false;

        cur = nxt[cur][i - 'a'];
    }

    return chk[cur];
}

void erase(string s)
{
    ll cur = 0;

    for(char i : s)
        cur = nxt[cur][i - 'a'];

    chk[cur] = false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
}
