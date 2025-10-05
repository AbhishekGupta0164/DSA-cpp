#include <iostream>
#include <vector>
using namespace std;
   //to print subsets with all permutation in array by swap index value
class Solution {
public:
    void getperms(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        // Base case: all positions fixed
        if (idx == nums.size()) {
            ans.push_back(nums); // store current permutation
            return;
        }

        // Swap each element with current index and recurse
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);          // choose element for current position
            getperms(nums, idx + 1, ans);      // recurse for next position
            swap(nums[idx], nums[i]);          // backtrack
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        getperms(nums, 0, ans);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};

    Solution sol;                       // Object of Solution class
    vector<vector<int>> res = sol.permute(nums);

    // Print all permutations
    for (auto &v : res) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
