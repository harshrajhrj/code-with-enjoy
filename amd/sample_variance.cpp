#include <bits/stdc++.h>
using namespace std;

double calcSampleVariance(const vector<int> &data)
{
    if (data.size() < 2)
        return 0.0;

    double sum = accumulate(data.begin(), data.end(), 0.0);
    double mean = sum / data.size();

    double sqSum = 0.0;

    for (int num : data)
    {
        sqSum += (num - mean) * (num - mean);
    }

    // Sample variance divides by N-1, not N
    return sqSum / (data.size() - 1);
}
int main()
{
    return 0;
}