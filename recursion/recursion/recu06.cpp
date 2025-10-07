#include<iostream>
using namespace std;

//   to find nth fibonacci number 
int fibo(int n){
    if(n==0 || n==1){ // base case
        return n;

    }
    return fibo(n-1)+fibo(n-2);

}
int main(){
    int n;
    cout<<"enter N=  ";
    cin>>n;
    cout<<fibo(n)<<endl;
    return 0;

}