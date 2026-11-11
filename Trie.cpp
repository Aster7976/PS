ll n, len, letter;
vector<char> chk(n * len);
vector nxt(n * len, vector<ll>(letter));
ll cnt = 1;

void init()
{
    for(ll i = 0; i < n * len; i++)
        for(ll j = 0; j < letter; j++)
            nxt[i][j] = -1;
}

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
