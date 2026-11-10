ll half(pll x)
{
    return (x.S < 0 || (x.S == 0 && x.F < 0));
}

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

bool cmp(pll a, pll b)
{
    ll ha = half(a);
    ll hb = half(b);

    if(ha != hb)
        return ha < hb;

    ll c = ccw({0, 0}, a, b);
    return c > 0;
}
