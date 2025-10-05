#include<iostream>
using namespace std;
//   to print a number from n to 1 using recursion
void pritNum(int n){
   if (n==1){
    cout<<" 1\n ";
    return ;
   }
 cout<<n<<" ";
 pritNum(n-1);
   }
int main(){
   pritNum(500);

    return 0;
}