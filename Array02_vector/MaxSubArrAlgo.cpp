  #include<iostream>
  #include<climits>
  using namespace std;
  // Kadane's Algorithm (MSS - Maximum Subarray Sum) O(n)
  int main(){
   int i,n=6;
    int arr[n] ={-2,1,-3,4,5,-8};
    int maxSum = INT_MIN;

         for (int i = 0; i < n; i++) {
              int currSum =0;
             currSum += arr[i];
            maxSum = max(currSum,maxSum);

            if(currSum <0 ){
                currSum = 0;
                
            }
        }
        cout << "Maximum Subarray Sum = " << maxSum << endl;
        return 0;
    }
 