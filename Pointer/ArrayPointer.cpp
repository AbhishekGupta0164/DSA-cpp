#include<iostream>
using namespace std;  

int main(){
     int arr[] ={1,2,3,4,5};
     int a=15,b=10;
     int *ptr = &a;
      ptr = &b;

        cout<< *ptr << endl;
     return 0;

}