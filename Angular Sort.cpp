bool cmp(pll a, pll b)
{
    ll ha = (a.S < 0 || (a.S == 0 && a.F < 0));
    ll hb = (b.S < 0 || (b.S == 0 && b.F < 0));

    if(ha != hb)
        return ha < hb;

    ll c = a.F * b.S - a.S * b.F;
    return c > 0;
}
