#include <iostream>
using namespace std;

//reverse / swaping of array

void reverseArray(int arr[],int size){
    int start =0 ,end = size -1;
    while(start < end){
        swap(arr[start],arr[end]);
        start ++;
        end -- ;
    
    }
}
int main(){
    int arr[]= {2,4,6,8,44,10};
    int size = 6;
    reverseArray(arr,size);
    for(int i= 0; i<size ;i++){
      cout<< arr[i]<<" ";

    }
    
cout<< endl;

    return 0;
}