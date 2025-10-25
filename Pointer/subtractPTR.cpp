#include<iostream>
using namespace std;
 
// pointer arithmetic subtraction and comparision

int main(){
    int arr[] = {10,20,30,40,50};
    int *ptr2; 
    int *ptr1 = ptr2 +2;
    cout<< ptr1 -ptr2 <<endl; // 8 bytes means 2 integer

    cout<< ptr1<< endl;
    cout<< ptr2<< endl;
    cout<<(ptr1 == ptr2)<< endl;
    cout<< (ptr1 < ptr2) << endl;

     return 0;
}