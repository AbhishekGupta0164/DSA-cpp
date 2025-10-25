#include<iostream>
using namespace std;


// to print address of variable using pointer

int main(){
    int a =10;
    int *ptr = &a;
    int **ptr2=&ptr;

    cout<< &a << endl;
    cout<< *(&a)<< endl;
    cout<< *(ptr)<< endl;
    cout<< ptr << endl;
    cout<< &ptr << endl;
    cout<< ptr2 <<endl;
    cout<< *(ptr2) << endl;
    cout<< &ptr2 << endl;


    return 0;

} 