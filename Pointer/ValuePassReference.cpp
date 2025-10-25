#include<iostream>
using namespace std;

//pass by reference using pointer
void changeA(int ){  //pass by value
 
 
}
int main(){
int a=10;
changeA(&a);
cout<< "inside main fn "<< a << endl;

return 0;
}