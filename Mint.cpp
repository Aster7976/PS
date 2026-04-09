// BOJ 10869

#include <bits/stdc++.h>

using namespace std; 
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

#define F first
#define S second

const ll INF = 2e18;

template <ll MOD>
class Mint {
public:
    ll v;

    Mint() : v(0) {}

    template <typename T>
    Mint(T x) {
        v = (ll)(x % MOD);
        if (v < 0) v += MOD;
    }

    static ll mod() { return MOD; }

    ll val() const { return v; }
    explicit operator ll() const { return v; }
    explicit operator int() const { return (int)v; }

    Mint operator+() const { return *this; }
    Mint operator-() const { return Mint(0) - *this; }

    Mint& operator+=(const Mint& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    Mint& operator*=(const Mint& o) {
        v = v * o.v % MOD;
        return *this;
    }
    Mint& operator/=(const Mint& o) {
        return *this *= o.inv();
    }

    Mint operator+(const Mint& o) const { return Mint(*this) += o; }
    Mint operator-(const Mint& o) const { return Mint(*this) -= o; }
    Mint operator*(const Mint& o) const { return Mint(*this) *= o; }
    Mint operator/(const Mint& o) const { return Mint(*this) /= o; }

    Mint& operator++() { return *this += 1; }
    Mint& operator--() { return *this -= 1; }
    Mint operator++(int) { Mint t = *this; ++*this; return t; }
    Mint operator--(int) { Mint t = *this; --*this; return t; }

    bool operator==(const Mint& o) const { return v == o.v; }
    bool operator!=(const Mint& o) const { return v != o.v; }
    bool operator< (const Mint& o) const { return v <  o.v; }
    bool operator<=(const Mint& o) const { return v <= o.v; }
    bool operator> (const Mint& o) const { return v >  o.v; }
    bool operator>=(const Mint& o) const { return v >= o.v; }

    Mint inv() const {
        ll a = v, b = MOD, x = 1, y = 0;
        while (b) {
            ll q = a / b;
            a -= q * b; swap(a, b);
            x -= q * y; swap(x, y);
        }
        return Mint(x);
    }

    Mint pow(ll e) const {
        if (e < 0) return inv().pow(-e);
        Mint base = *this, result = 1;
        for (; e > 0; e >>= 1) {
            if (e & 1) result *= base;
            base *= base;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Mint& m) {
        return os << m.v;
    }
    friend std::istream& operator>>(std::istream& is, Mint& m) {
        ll x; is >> x; m = Mint(x);
        return is;
    }

    template <typename T>
    friend Mint operator+(T l, const Mint& r) { return Mint(l) + r; }
    template <typename T>
    friend Mint operator-(T l, const Mint& r) { return Mint(l) - r; }
    template <typename T>
    friend Mint operator*(T l, const Mint& r) { return Mint(l) * r; }
    template <typename T>
    friend Mint operator/(T l, const Mint& r) { return Mint(l) / r; }
};

using mint = Mint<998244353>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;

    mint c = a;
    mint d = b;

    c += 998244353;
    d += 998244353;

    cout << c + d << '\n';
    cout << a - b << '\n';
    cout << c * d << '\n';
    cout << a / b << '\n';
    cout << a % b << '\n';
}
