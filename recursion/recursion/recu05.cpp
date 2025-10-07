#include <iostream>
using namespace std;
//  sum of first n nums 
int sum(int n){
    if (n==1){
        return 1;
    }
        return n+sum(n-1);
}

int main(){
    int n;
    cout<< "enter N = ";
    cin>>n;
    cout<< sum(n)<<endl;
    return 0;

}