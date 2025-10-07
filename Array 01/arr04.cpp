#include <iostream>
using namespace std;

// to Search any value in array
int linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {2, 5, 8, 6, 4, 9, 5, 77};
    int size = 8;
    int target = 77;
    cout << linearSearch(arr, size, target) << endl;

    return 0;
}
