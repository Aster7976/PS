template <ll MOD>
class Mint
{
public:
    ll x;

    Mint() : x(0) {}

    template <typename T>
    Mint(T y)
    {
        x = (ll)(y % MOD);
        if(x < 0)
            x += MOD;
    }

    explicit operator ll() const { return x; }
    explicit operator int() const { return (int)x; }
    Mint operator-() const { return Mint() - *this; }

    Mint& operator+=(const Mint& y)
    {
        x += y.x;
        if(x >= MOD)
            x -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint& y)
    {
        x -= y.x;
        if(x < 0)
            x += MOD;
        return *this;
    }
    Mint& operator*=(const Mint& y)
    {
        x = x * y.x % MOD;
        return *this;
    }
    Mint& operator/=(const Mint& y) { return *this *= y.inv(); }

    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }

    Mint& operator++() { return *this += 1; }
    Mint& operator--() { return *this -= 1; }
    Mint operator++(int)
    {
        Mint t = *this;
        ++*this;
        return t;
    }
    Mint operator--(int)
    {
        Mint t = *this;
        --*this;
        return t;
    }

    friend bool operator==(const Mint& a, const Mint& b) { return a.x == b.x; }
    friend bool operator!=(const Mint& a, const Mint& b) { return a.x != b.x; }
    friend bool operator<(const Mint& a, const Mint& b) { return a.x < b.x; }
    friend bool operator<=(const Mint& a, const Mint& b) { return a.x <= b.x; }
    friend bool operator>(const Mint& a, const Mint& b) { return a.x > b.x; }
    friend bool operator>=(const Mint& a, const Mint& b) { return a.x >= b.x; }

    Mint inv() const { return pow(MOD - 2); }

    Mint pow(ll y) const
    {
        if(y < 0)
            return inv().pow(-y);

        Mint base = *this;
        Mint result = 1;

        while(y > 0)
        {
            if(y & 1)
                result *= base;
            base *= base;
            y >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream& out, const Mint& y) { return out << y.x; }
    friend istream& operator>>(istream& in, Mint& y)
    {
        ll a;
        in >> a;
        y = Mint(a);
        return in;
    }
};

using mint = Mint<998244353>;
