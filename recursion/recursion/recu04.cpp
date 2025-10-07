#include <iostream>
using namespace std;
//    factorial of  n
int factorial(int n){
    if(n==0){  //base case 
        return 1;

    }
    return n*factorial(n-1);

}
int main(){
    cout<<factorial(5)<<endl;
    return 0;

}
