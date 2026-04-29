const int C = 1000001;

vector<char> prime(C, true);

void seive()
{
    prime[1] = false;

    for(int i = 2; i * i < C; i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j < C; j += i)
                prime[j] = false;
        }
    }   
}
