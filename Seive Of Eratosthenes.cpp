ll n;
vector<char> prime(n, true);

void seive()
{
    prime[1] = false;

    for(int i = 2; i * i < n; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j < n; j += i)
                prime[j] = false;
        }
    }   
}
