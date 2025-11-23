#include <iostream>
#include <vector>
using namespace std;

// Search in rotated sorted array

int main()
{
    int tar = 4;
    vector<int>arr = {2, 3, 4, 5, 6, 7, 8, 9};
    int st = 0, end = arr.size() - 1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (arr[mid] == tar)
        {
            cout<<"Found at index :  "<<mid;
            return 0;
        }

        if (arr[st] <= arr[mid])
        { // left sorted
            if (arr[st] <= tar && tar <= arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else
        { // right sorted
            if (arr[mid] <= tar && tar <= arr[end])
            {
                st = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    cout<<"not found";
}