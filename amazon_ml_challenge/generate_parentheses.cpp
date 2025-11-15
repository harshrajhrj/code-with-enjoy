#include <bits/stdc++.h>
using namespace std;

vector<string> all_parentheses(int n)
{
    vector<string> result;

    function<void(int, int, string)> generate = [&](int l, int r, string t)
    {
        if (l > n || r > n)
            return;

        if (l < r)
            return;

        if (l == n && r == n)
        {
            result.push_back(t);
            return;
        }

        generate(l + 1, r, t + '(');
        generate(l, r + 1, t + ')');
    };

    generate(0, 0, "");

    return result;
}
int main()
{
    int n = 2;

    vector<string> result = all_parentheses(n);
    for (auto &str : result)
    {
        cout << str << endl;
    }

    return 0;
}