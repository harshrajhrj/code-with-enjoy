#include <bits/stdc++.h>
using namespace std;

int binary_to_integer(string s) {
    int res = 0;
    int n = s.length();
    int multiplier = 1;

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1')
            res += multiplier;
        multiplier *= 2;
    }


    return res;
}

int main() {
    cout<<binary_to_integer("101110");
}