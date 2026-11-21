void line_intersection(pll a, pll b, pll c, pll d)
{
    ll c1 = ccw(a, b, c) * ccw(a, b, d);
    ll c2 = ccw(c, d, a) * ccw(c, d, b);

    if(a > b)
        swap(a, b);
    if(c > d)
        swap(c, d);
    
    if(c1 == 0 && c2 == 0)
        cout << (b >= c && d >= a);
    else
        cout << (c1 <= 0 && c2 <= 0);
}
