#include <iostream>
using namespace std;

// to print arr elements
int main()
{

    int size; 
    cout << "size of arr: ";
    cin>>size;

    int arr[size];
    cout << "enter elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "entered arr is: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}