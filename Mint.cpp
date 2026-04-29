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

    ll mod() const
    {
        return MOD;
    }
    ll val() const
    {
        return x;
    }
    operator ll() const
    {
        return (ll)x;
    }
    operator int() const
    {
        return (int)x;
    }

    Mint operator+() const
    {
        return *this;
    }
    Mint operator-() const
    {
        return Mint(0) - *this;
    }

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
    Mint& operator/=(const Mint& y)
    {
        return *this *= y.inv();
    }

    Mint operator+(const Mint& y) const
    {
        return Mint(*this) += y;
    }
    Mint operator-(const Mint& y) const
    {
        return Mint(*this) -= y;
    }
    Mint operator*(const Mint& y) const
    {
        return Mint(*this) *= y;
    }
    Mint operator/(const Mint& y) const
    {
        return Mint(*this) /= y;
    }

    Mint& operator++()
    {
        return *this += 1;
    }
    Mint& operator--()
    {
        return *this -= 1;
    }
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

    bool operator==(const Mint& y) const
    {
        return x == y.x;
    }
    bool operator!=(const Mint& y) const
    {
        return x != y.x;
    }
    bool operator<(const Mint& y) const
    {
        return x < y.x;
    }
    bool operator<=(const Mint& y) const
    {
        return x <= y.x;
    }
    bool operator>(const Mint& y) const
    {
        return x > y.x;
    }
    bool operator>=(const Mint& y) const
    {
        return x >= y.x;
    }

    Mint inv() const
    {
        ll a = x;
        ll b = MOD;
        ll c = 1;
        ll d = 0;

        while(b)
        {
            ll q = a / b;
            a -= q * b;
            swap(a, b);
            c -= q * d;
            swap(c, d);
        }

        return Mint(c);
    }

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

    friend std::ostream& operator<<(std::ostream& out, const Mint& y)
    {
        return out << y.x;
    }
    friend std::istream& operator>>(std::istream& in, Mint& y)
    {
        ll a;
        in >> a;
        y = Mint(a);
        return in;
    }

    template<typename T>
    friend Mint operator+(T l, const Mint& r)
    {
        return Mint(l) + r;
    }
    template<typename T>
    friend Mint operator-(T l, const Mint& r)
    {
        return Mint(l) - r;
    }
    template<typename T>
    friend Mint operator*(T l, const Mint& r)
    {
        return Mint(l) * r;
    }
    template<typename T>
    friend Mint operator/(T l, const Mint& r)
    {
        return Mint(l) / r;
    }
};

using mint = Mint<998244353>;
