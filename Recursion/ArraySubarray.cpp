#include <iostream>
#include <string>
#include <vector>
using namespace std;
void subarray(int arr[], int n, int idx, vector<int> ans) // yaha pr address operator nhi lagana
{
    if (idx == n)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "  ";
        cout << endl;
        return;
    }
    subarray(arr, n, idx + 1, ans);
    if (ans.size() == 0 || arr[idx - 1] == ans[ans.size() - 1])
    {
        ans.push_back(arr[idx]);
        subarray(arr, n, idx + 1, ans);
    }
}

int main()
{
    int arr[] = {3,1,2,4};
    vector<int> v;
    int n = sizeof(arr) / 4;
    // subarray(arr, n, 0, v);

        // for (int i = 0; i < n; i++) {
        //     for (int j = i; j < n; j++) {
        //         for (int k = i; k < j +1; k++) {
        //            cout<<arr[k]<<"  ";
        //         }
        //        cout<<endl;
        //     }
        // }


    return 0;
}