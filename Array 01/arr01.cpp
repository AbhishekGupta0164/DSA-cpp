#include <iostream>
using namespace std;
// to store variable in array
int main()
{
    int size = 5;
    int i;
    int marks[size];

    cout<<"enter value : ";

   for (int i = 0; i < size; i++)
    {  
        cin >> marks[i];
    }

    //  loop 0 to size -1

    for (int i = 0; i < size; i++)
    {
        cout << marks[i] << endl;
    }

    return 0;
}