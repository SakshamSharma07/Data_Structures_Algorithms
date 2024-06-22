#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if (n == 2)
        return true;
    for (int i = 2; i < (n/2)+1; i++)
    {
        if (n % 2 == 0)
            return false;
    }
    return true;
}
vector<int> getPrimes(int n)
{
    map<int, int> mp;
    vector<int> ans;
    int i = 2;
    int j = n - 2;
    while (i <= j)
    {
        // cout<<i<<" "<<j<<endl;
        if (isPrime(i) && isPrime(j))
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else
        {
            i++;
            j--;
        }
    }
    ans.push_back(-1);
    ans.push_back(-1);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans = getPrimes(n);
    for (auto i : ans)
    {
        cout << i << " ";
        }

    return 0;
}
