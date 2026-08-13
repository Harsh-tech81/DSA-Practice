
// Printing Subsequences of the array
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSubset(int arr[], int n, int idx, vector<int> ans, int k) // yaha pr address operator nhi lagana
{
    if (idx == n)
    {
        if (ans.size() == k)
        {
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << "  ";
            cout << endl;
        }
        return;
    }
    if (ans.size() + (n - idx) < k)
        return; // Time Complexity better ho jayge esha kr ne se
    printSubset(arr, n, idx + 1, ans, k);
    ans.push_back(arr[idx]);
    printSubset(arr, n, idx + 1, ans, k);
}




// void printSubset2( string ans,string orig,int idx, int k) // yaha pr address operator nhi lagana
// {
//     if (idx == orig.size())
//     {
//         if (ans.size() == k)
//         {
//             for (int i = 0; i < ans.size(); i++)
//                 cout << ans[i];
//             cout << endl;
//         }
//         return;
//     }
//     if(ans.size()+(orig.length()-idx)<k) return;   // Time Complexity better ho jayge esha kr ne se
//     printSubset2(ans,orig ,idx + 1,k);
//     // ans.push_back(arr[idx]);
//     printSubset2(ans+orig[idx],orig, idx + 1,k);
// }

void printSubset4(int arr[], int n, int idx, vector<int> ans) // yaha pr address operator nhi lagana
{
    if (idx == n)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << "  ";
        cout << endl;

        return;
    }

    printSubset4(arr, n, idx + 1, ans);
    ans.push_back(arr[idx]);
    printSubset4(arr, n, idx + 1, ans);
}
// void printSubset21( string ans,string orig,int idx) // yaha pr address operator nhi lagana
// {
//     if (idx == orig.size())
//     {
    
//             for (int i = 0; i < ans.size(); i++)
//                 cout << ans[i];
//             cout << endl;
        
//         return;
//     }
//       // Time Complexity better ho jayge esha kr ne se
//     printSubset21(ans,orig ,idx + 1);
//     // ans.push_back(arr[idx]);
//     printSubset21(ans+orig[idx],orig, idx + 1);
// }
int main()
{

    int arr[] = {1,1,1,1};
    
    // string s= "1001010";
    vector<int> ans;
    vector<int> v;
    int k = 3;
    int n = sizeof(arr) / 4;
    // printSubset(arr,n,0, v,2);
    // printSubset4(arr, n, 0, ans);
    printSubset4(arr, n, 0, ans);
// printSubset21("",s,0);

    return 0;
}