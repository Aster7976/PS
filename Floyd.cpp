#include <bits/stdc++.h>

using namespace std;

#define inf 1e8
int d[101][101];
int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fill(d[i], d[i] + n + 1, inf);
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for(int i = 1; i <= n; i++)
        d[i][i] = 0;

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