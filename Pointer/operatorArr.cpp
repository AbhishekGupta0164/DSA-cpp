#include <iostream>
using namespace std;
 // pointer arithmetic
int main(){
    int arr[] = {10,20,30,40,50};

    int a=10;
    int *ptr =&a;
    cout<< ptr << endl;
    ptr++;
    cout<< ptr << endl; //+4 bytes
    ptr--;
    cout<< ptr << endl; //-4 bytes
     return 0;

}