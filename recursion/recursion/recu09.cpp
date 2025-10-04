#include <iostream>
#include <vector>
using namespace std;
//   to print all subsets of arr
void printSubsets(vector<int> &arr, vector<int> &ans, int i)
{
    if (i == arr.size())
    {
        // print current subset
        for (int vat : ans)
        {
            cout << vat << " ";
        }
        cout << endl;
        return;
    }

    // include current element
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // backtrack (exclude current element)
    ans.pop_back();
    printSubsets(arr, ans, i + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans;  // this "ans" is only in main
    printSubsets(arr, ans, 0);
    return 0;
}
