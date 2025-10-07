#include <iostream>
using namespace std;

//  doubling value of  array
void changeArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 2 * arr[i];
    }
}
int main()
{
    int arr[] = {1, 2, 4, 5};
    changeArr(arr, 4);
    cout << "in main\n";
    for (int i = 0; i < 4; i++)
    { // 2 4 8 10
        cout << arr[i] << " ";
    }
    cout << endl;
}