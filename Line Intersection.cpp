vector<pll> p(5);

ll ccw(pll a, pll b, pll c)
{
    ll cp = (b.F - a.F) * (c.S - a.S)
    - (b.S - a.S) * (c.F - a.F);

    if(cp > 0)
        return 1;
    else if(cp < 0)
        return -1;
    else
        return 0;
}

void line_intersection()
{
    ll c1 = ccw(p[1], p[2], p[3]) * ccw(p[1], p[2], p[4]);
    ll c2 = ccw(p[3], p[4], p[1]) * ccw(p[3], p[4], p[2]);

    if(c1 == 0 && c2 == 0)
    {
        if(p[1] > p[2])
            swap(p[1], p[2]);
        if(p[3] > p[4])
            swap(p[3], p[4]);

        cout << (p[2] >= p[3] && p[4] >= p[1]);
    }
    else
        cout << (c1 <= 0 && c2 <= 0);
}
