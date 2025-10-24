#include<iostream>
using namespace std;
 // to check majority element in an array
int main(){
    int arr[] = {2,6,4,5,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    int candidate = arr[0];

    for (int i = 0; i < len; i++) {
        if (count == 0) {
            cout << "here " << i << endl; 
            candidate = arr[i];
            count = 1;
        } else {
            if (arr[i] == candidate)
                count++;
            else
                count--;
        }
    }

    cout << "Majority Element: " << candidate << endl;
    return 0;
}
