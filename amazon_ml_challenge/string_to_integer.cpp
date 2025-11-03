#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "-91283472332";

    int index = 0;
    int length = s.size();

    while (index < length && s[index] == ' ')
    {
        ++index;
    }

    int sign = 1; // by default

    if (index < length && (s[index] == '-' || s[index] == '+'))
    {
        sign = (s[index] == '-' ? -1 : 1);
        ++index;
    }

    int result = 0;

    while (index < length && isdigit(s[index]))
    {
        int digit = s[index] - '0';
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX & 10))
        {
            result = (sign == 1) ? INT_MAX : INT_MIN;
            break;
        }

        result = result * 10 + digit;
        ++index;
    }

    cout << result * sign;

    return 0;
}