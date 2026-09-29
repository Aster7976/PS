string base_conversion(string& s, ll from, ll to)
{
    if(s == "" || s == "0")
        return "0";

    vector<ll> num;

    for(char c : s)
    {
        if(c >= 'a')
            num.push_back(c - 'a' + 36);
        else if(c >= 'A')
            num.push_back(c - 'A' + 10);
        else
            num.push_back(c - '0');
    }

    string res;
    ll st = 0;

    while(st < num.size())
    {
        ll rem = 0;

        for(ll i = st; i < num.size(); i++)
        {
            ll cur = num[i] + rem * from;
            num[i] = cur / to;
            rem = cur % to;
        }

        char add;

        if(rem >= 36)
            add = 'a' + rem - 36;
        else if(rem >= 10)
            add = 'A' + rem - 10;
        else
            add = '0' + rem;

        res += add;

        while(st < num.size() && num[st] == 0)
            st++;
    }

    reverse(res.begin(), res.end());

    return res;
}
