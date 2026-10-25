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

void line_intersection(pll a, pll b, pll c, pll d)
{
    ll c1 = ccw(a, b, c) * ccw(a, b, d);
    ll c2 = ccw(c, d, a) * ccw(c, d, b);

    if(c1 == 0 && c2 == 0)
    {
        if(a > b)
            swap(a, b);
        if(c > d)
            swap(c, d);

        cout << (b >= c && d >= a);
    }
    else
        cout << (c1 <= 0 && c2 <= 0);
}
