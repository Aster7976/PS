ll n, m, k; // 길이가 m인 문자열 n개, 글자의 종류 k개
vector<char> check(n * m);
ll nxt[n * m][k];
ll cnt = 2;

void init()
{
    for(ll i = 0; i < n * m; i++)
        for(ll j = 0; j < k; j++)
            nxt[i][j] = -1;
}

void insert(string& s)
{
    ll cur = 1;
    for(auto i : s)
    {
        if(nxt[cur][i - 'a'] == -1)
            nxt[cur][i - 'a'] = cnt++;
        cur = nxt[cur][i - 'a'];
    }
    check[cur] = true;
}

bool find(string& s)
{
    ll cur = 1;
    for(auto i : s)
    {
        if(nxt[cur][i - 'a'] == -1)
            return false;
        cur = nxt[cur][i - 'a'];
    }
    return check[cur];
}

void erase(string& s)
{
    ll cur = 1;
    for(auto i : s)
    {
        if(nxt[cur][i - 'a'] == -1)
            return;
        cur = nxt[cur][i - 'a'];
    }
    check[cur] = false;
}
