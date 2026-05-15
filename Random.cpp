    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());  
    std::uniform_int_distribution<ll> dist(l, r);

    cout << dist(rng) << ' ';
