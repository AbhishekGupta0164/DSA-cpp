#include<iostream>
# include<vector>
using namespace std;
// leetcode problem 136
// using vector
// to print the num that is unique in array where every other element appears twice
class Solution {
public:
    int singleNumber(vector<int>& nums) {
          int ans =0;
          for(int val: nums){
            ans =ans^val;
          }
          return ans;  
    }
};

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution sol;
    cout << "The unique number is: " << sol.singleNumber(nums) << endl;
    return 0;
}