#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets
void getallSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
{
    if (i == nums.size())
    {
        allSubsets.push_back(ans);  // store current subset
        return;
    }

    // include current element
    ans.push_back(nums[i]);
    getallSubsets(nums, ans, i + 1, allSubsets);

    // backtrack (exclude current element)
    ans.pop_back();
    getallSubsets(nums, ans, i + 1, allSubsets);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;
    vector<vector<int>> allSubsets;

    getallSubsets(arr, ans, 0, allSubsets);

    // Print all subsets
    cout << "All subsets are:\n";
    for (auto subset : allSubsets)
    {
        cout << "{ ";
        for (int val : subset)
        {
            cout << val << " ";
        }
        cout << "}\n";
    }

    return 0;
}
