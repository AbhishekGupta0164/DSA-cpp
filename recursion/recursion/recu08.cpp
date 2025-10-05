#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int binsearch(vector<int> &arr, int tar, int st, int end)
    {
        if (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (arr[mid] == tar)
                return mid;
            else if (arr[mid] <= tar)
            

                return binsearch(arr, tar, mid + 1, end);
            
            else
                return binsearch(arr, tar, st, mid - 1);
        }
    
    return -1;
    }


     int search(vector<int> &arr, int tar){
      
    return binsearch(arr, tar, 0, arr.size() - 1);
      }

 };

int main()
{
    solution s;
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 58;
    int index = s.search(arr, target);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}