class Node
{
public:
    Node* l = nullptr;
    Node* r = nullptr;
    ll sum = 0;
};

Node* root = new Node;

ll query(Node* cur, ll st, ll en, ll l, ll r)
{
    if(!cur)
        return 0;

    if(r < st || en < l)
        return 0;

    if(l <= st && en <= r)
        return cur->sum;

    ll m = (st + en) / 2;
    ll lsum = query(cur->l, st, m, l, r);
    ll rsum = query(cur->r, m + 1, en, l, r);
    return lsum + rsum;
}

void update(Node* cur, ll st, ll en, ll idx, ll val)
{
    if(st == en)
    {
        cur->sum = val;
        return;
    }

    ll m = (st + en) / 2;
    
    if(idx <= m)
    {
        if(!cur->l)
            cur->l = new Node();
        
        update(cur->l, st, m, idx, val);
    }
    else
    {
        if(!cur->r)
            cur->r = new Node();

        update(cur->r, m + 1, en, idx, val);
    }

    ll x = cur->l ? cur->l->sum : 0;
    ll y = cur->r ? cur->r->sum : 0;
    cur->sum = x + y;
}
