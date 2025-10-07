#include <iostream>
#include <climits>
using namespace std;

// find smallest value
int main()
{
    int nums[] = {5, 9, 6, 7, 1};
    int size = 5;
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < size; i++)   //min ,max
    {   
        // if (nums[i] < smallest)
        // {
        //     smallest = nums[i];
        // } 
            // //** same working with single line code without if loop
        smallest = min(nums[i],smallest);
        largest = max(nums[i],largest);

    }
    cout << "smallest = " << smallest << endl;
    cout<<"largest = "<< largest << endl;
    return 0;
}