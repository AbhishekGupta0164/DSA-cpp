#include <iostream>
#include <vector>
using namespace std;
//find peak index in mountain array
int main()
{

    vector<int>arr = {2,3,4,5,66,7,9};

    int st = 1, end = arr.size() - 2;

    while(st <= end){
    int mid = st + (end - st) / 2;
    if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
    {
        cout<<"Peak Found at index: "<<mid;
        return mid;
    }
    else if (arr[mid - 1] < arr[mid])
    { // right
        st = mid + 1;
    }
    else
    { // left
        end = mid - 1;
    }
  }
return -1;
}