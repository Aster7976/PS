ll n;
vector<vector<ll>> adj(n);
vector<ll> order(n);
vector<ll> low(n);
vector<bool> stc(n);
stack<ll> st;
vector<vector<ll>> scc;
ll turn = 0;

void dfs(ll cur)
{
    order[cur] = low[cur] = ++turn;
    st.push(cur);
    stc[cur] = true;

    for(auto next : adj[cur])
    {
        if(!order[next])
        {
            dfs(next);
            low[cur] = min(low[cur], low[next]);
        }
        else if(stc[next])
            low[cur] = min(low[cur], order[next]);
    }

    if(low[cur] == order[cur])
    {
        vector<ll> tmp;

        while(true)
        {
            ll x = st.top();
            st.pop();

            stc[x] = false;
            tmp.push_back(x);

            if(x == cur)
                break;
        }

        scc.push_back(tmp);
    }
}
