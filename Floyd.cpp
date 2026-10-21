ll n;
vector dist(n, vector<ll>(n, INF));
vector nxt(n, vector<ll>(n));

void floyd()
{
    for(ll i = 1; i <= n; i++)
        dist[i][i] = 0;

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
        {   
            cin >> dist[i][j];
            nxt[i][j] = j;
        }

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= n; j++)
            for(ll k = 1; k <= n; k++)
                if(dist[j][k] > dist[j][i] + dist[i][k])
                {
                    dist[j][k] = dist[j][i] + dist[i][k];
                    nxt[j][k] = nxt[j][i];
                }
}
