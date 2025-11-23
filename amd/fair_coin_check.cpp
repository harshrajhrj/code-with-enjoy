#include <bits/stdc++.h>
using namespace std;

/**
 * @brief We use a simple Z-Score test. For a fair coin (p=0.5),
 * the expected Mean is N x 0.5 and
 * Standard Deviation is \sqrt{N x 0.5 x (1-0.5)}.
 * If the result is more than 1.96 standard deviations away (95% confidence),
 * it's biased.
 *
 * @param flips
 * @param head
 * @return true
 * @return false
 */
bool isCoinFair(int flips, int heads)
{
    double p = 0.5;
    double mean = flips * p;
    double stdDev = sqrt(flips * p * (1 - p));

    double zScore = (heads - mean) / stdDev;

    // Check against 95% confidence interval (-1.96 to +1.96)
    // If zScore is outside this range, the coin is likely biased.
    if (abs(zScore) > 1.96)
    {
        return false; // biased
    }

    return true;
}

// Note: For 8 Tails (2 Heads), Z-Score is ~1.89, so it is technically "Fair"
// but very close to the limit.

int main()
{
    cout << isCoinFair(10, 2);
}