//BOJ 11404

#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int d[101][101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i != j)
                d[i][j] = inf;
        }
    }

    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(d[i][j] == inf)
                cout << "0 ";
            else
                cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

