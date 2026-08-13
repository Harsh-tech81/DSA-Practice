#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printSubset(int arr[], int n, int idx, vector<int> ans) // yaha pr address operator nhi lagana
{
    if (idx == n)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "  ";
        cout << endl;
        return;
    }
    printSubset(arr, n, idx + 1, ans);
    ans.push_back(arr[idx]);
    printSubset(arr, n, idx + 1, ans);
}

int main()
{

    int arr[] = {1, 2,3}; // Total Number of the subsets is 2^n where n is the no. of Elements in an array
    vector<int> v;
    int n = sizeof(arr) / 4;
    printSubset(arr, n, 0, v);

    return 0;
}