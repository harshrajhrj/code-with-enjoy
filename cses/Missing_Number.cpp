#include <bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& nums)
{
    // the sum of the number must be n * (n + 1)/2
    long long required_sum = (long long)n * (n + 1) / 2;
    long long actual_sum = 0;
    for(auto ele : nums)
    {
        actual_sum += (long long)ele;
    }

    // print missing number
    cout << required_sum - actual_sum;
}




int main()
{
    int n;
    cin>>n;
    vector<int> arr(n - 1);

    for(int i = 0; i < n - 1; i++)
    {
        cin>>arr[i];
    }

    solve(n, arr);
}