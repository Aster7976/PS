ll n;
ll board[n][n];
ll dp[n][1 << n];

void init()
{
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 1 << 16; j++)
            dp[i][j] = -1;
    }
}

ll tsp(ll cur, ll visited)
{
    if(visited == (1 << n) - 1)
    {
        if(board[cur][0] != 0)
            return board[cur][0];
        else
            return INF;
    }

    ll& ret = dp[cur][visited];

    if(ret != -1)
        return ret;

    ret = INF;
    for(ll next = 0; next < n; next++)
    {
        if(!(visited & (1 << next)) && board[cur][next] != 0)
        {
            ret = min(ret, tsp(next, visited | (1 << next)) + board[cur][next]);
        }
    }

    return ret;
}
