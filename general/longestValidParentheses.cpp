#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string str)
{
    int maxLen = 0;
    int n = str.size();

    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main()
{
    string str = ")()()(((((((((())))))))))";
    cout << longestValidParentheses(str);
    return 0;
}