#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;

        if (arr[0] <= arr[mid])
        {
            if (arr[0] <= target && target <= arr[mid])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (arr[mid] < target && target <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
    }

    return arr[left] == target ? left : -1;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 8, 9, 0, 1, 2};
    cout << search(arr, 4);
    return 0;
}