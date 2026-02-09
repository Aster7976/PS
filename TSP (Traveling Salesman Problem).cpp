// BOJ 2098

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int board[16][16];
int dp[16][1 << 16];

int n;

int tsp(int cur, int visited)
{
    if(visited == (1 << n) - 1)
    {
        if(board[cur][0] != 0)
            return board[cur][0];
        else
            return INF;
    }

    int& ret = dp[cur][visited];

    if(ret != -1)
        return ret;

    ret = INF;
    for(int next = 0; next < n; next++)
    {
        if(!(visited & (1 << next)) && board[cur][next] != 0)
        {
            ret = min(ret, tsp(next, visited | (1 << next)) + board[cur][next]);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 1 << 16; j++)
        {
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = tsp(0, 1);

    cout << ans;
}
