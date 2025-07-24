/**
 * Used to find first element in the given range that is greater than or equal to the given value
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> arr1 = {10, 15, 20, 25, 30, 35};
	vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};
	vector<int> arr3 = {10, 15, 25, 30, 35};
	
	int val = 20;
	
	cout << lower_bound(arr1.begin(), arr1.end(), val) - arr1.begin(); // using lower_bound() to check if val exists in arr1, single occurrence, prints 2
	cout << endl;
	
	cout << lower_bound(arr2.begin(), arr2.end(), val) - arr2.begin(); // using lower_bound() to check if val exists in arr2, multiple occurrence, prints 2
	cout << endl;
	
	cout << lower_bound(arr3.begin(), arr3.end(), val) - arr3.begin(); // using lower_bound() to check if val exists in arr3, no occurrence, prints 2 (index of next higher)
	cout << endl;
	
	return 0;
}
