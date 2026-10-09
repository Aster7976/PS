ll n;
vector<char> prime(n, true);
vector<ll> primes;

void seive()
{   
    prime[1] = false;

    for(ll i = 2; i * i < n; i++)
        if(prime[i])
            for(ll j = i * i; j < n; j += i)
                prime[j] = false;

    for(ll i = 2; i < n; i++)
        if(prime[i])
            primes.push_back(i);
}
