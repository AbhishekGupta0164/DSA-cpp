#include<iostream>
#include<climits>
using namespace std;

 // to print Max Subarrays and their sum 

int main(){
    int n = 5;
    int arr[n] ={1,2,3,4,5};
    int maxSum = INT_MIN;

   //  //  to print SubArrays
    
    // for(int st=0;st<=n;st++){
    //     for(int end =st; end<n;end++){
    //        for(int i=st; i<=end;i++){
    //            cout<< arr[i];
    //        }
    //        cout<<" ";
    //     }
    //     cout<< endl;
    // }

    // **************************
     
    // // to print Max SubArray Sum
    //// current sum =  0 at starting point
 
    for(int st=0;st<=n;st++){
       int currSum =0;
        for(int end =st; end<n;end++){
           currSum +=arr[end];
            maxSum = max(currSum ,maxSum);
        }
    }
     cout<<"max subarray sum = "<<maxSum<<endl;
    
    return 0;
}