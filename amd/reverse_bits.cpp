#include <bits/stdc++.h>
using namespace std;

// Reverse the bits of a 32-bit unsigned integer
// Direct register manipulation often requires reversing endianness or bit orders.

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
    {
        result <<= 1; // Shift result to the left to make room
        cout << result << " ";
        result |= (n & 1); // Add the last bit of n to result
        cout << result << " ";
        n >>= 1; // Shift n to the right to process next bit
        cout << n << " ";
        cout << endl;
    }

    return result;
}

int main()
{
    uint32_t num = 12;
    cout << reverseBits(num);
    return 0;
}