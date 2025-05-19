#include <bits/stdc++.h>

using namespace std;

int origin[22][22] = {};
int board[22][22] = {};

int n;

void rotate()
{
    int temp[22][22];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[i][j] = board[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            board[i][j] = temp[n - 1 - j][i];
        }
    }
}

void tilt(int dir)
{
    while(dir--)
        rotate();

    for(int i = 0; i < n; i++)
    {
        int tilted[22] = {};
        bool merged[22] = {};
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] != 0)
            {
                tilted[cnt] = board[i][j];
                if(tilted[cnt] == tilted[cnt - 1] && merged[cnt - 1] == false)
                {
                    tilted[cnt - 1] *= 2;
                    tilted[cnt] = 0;
                    merged[cnt - 1] = true;
                }
                else
                    cnt++;
            }
        }
        for(int k = 0; k < n; k++)
        {
            board[i][k] = tilted[k];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> origin[i][j];
        }
    }

    int ans = 0;

    for(int temp = 0; temp < 1024; temp++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                board[i][j] = origin[i][j];
            }
        }

        int brute = temp;
        for(int i = 0; i < 5; i++)
        {
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans = max(ans, board[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}