#include <iostream>
#include<vector>
using namespace std;

// check if array is shorted or not.
bool isSorted(vector<int> arr, int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }
    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}
int main()

 {    int n;
     cout<<"enter size of array: ";
     cin>>n;
    vector<int> arr(n);
    cout<<"enter "<<n<<"elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if (isSorted(arr, n))
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    
    return 0;
}
