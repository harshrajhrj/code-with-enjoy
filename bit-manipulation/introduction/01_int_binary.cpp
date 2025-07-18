#include <bits/stdc++.h>
using namespace std;

string integer_to_binary(int n) {
    string res = "";
    while(n > 1) {
        if(n % 2 == 1) res += '1';
        else res += '0';
        n = n / 2;
    }
    

    if(n % 2 == 1) res += '1';
    else res += '0';
    
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout<<integer_to_binary(46);
}