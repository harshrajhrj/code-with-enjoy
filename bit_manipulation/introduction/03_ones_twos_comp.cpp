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

int ones_complement(int n) {
    int number_of_bits = floor((log2(n))) + 1;
    return ((1 << number_of_bits) - 1) ^ n;
}

int twos_complement(int num) {
    int ones_comp = ones_complement(num);
    string s = integer_to_binary(ones_comp);
    int n = s.length();

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '0') {
            s[i] = '1';
            break;
        } else {
            s[i] = '0';
        }
    }

    if(s[0] == '0')
        s = '1' + s;

    return binary_to_integer(s);
}

int main() {
    cout<<ones_complement(13)<<endl;
    cout<<twos_complement(13);
}