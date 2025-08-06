#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> permutation = {1, 2, 3};
    vector<int> combination = {0, 0, 0, 1}; 

    do
    {
        for(int i = 0; i < 3; i++)
        {
            cout << permutation[i];
        }
        cout << '\n';
    } while (next_permutation(permutation.begin(), permutation.end()));
    
    cout << '\n';

    do
    {
        for(int i = 0; i < 4; i++)
        {
            if(combination[i] == 0)
            cout << i + 1;
        }
        cout << '\n';
    } while (next_permutation(combination.begin(), combination.end()));
}   
