#include <bits/stdc++.h>
using namespace std;

bool isMatchingPair(char left, char right)
{
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

int main()
{
    string s = "((((((())))))";

    string stack;
    int len = s.size();

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stack.push_back(s[i]);
        }
        else if (stack.empty() || !isMatchingPair(stack.back(), s[i]))
        {
            cout << false;
            return 0;
        }
        else
        {
            stack.pop_back();
        }
    }

    if (stack.empty())
        cout << true;
    else
        cout << false;

    return 0;
}