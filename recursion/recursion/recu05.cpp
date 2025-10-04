#include <iostream>
using namespace std;
//  sum of n nums
int sum(int n){
    if (n==1){
        return 1;
    }
        return n+sum(n-1);

    
}
int main(){
    cout<< sum(25)<<endl;
    return 0;

}