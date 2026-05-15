std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());  
std::uniform_int_distribution<ll> dist(l, r); // l, r 포함

ll x = dist(rng);
