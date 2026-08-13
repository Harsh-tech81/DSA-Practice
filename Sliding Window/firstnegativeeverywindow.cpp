// Sliding Window
// Brute force Approach now its T.C. is O(n*k)
// Now  Optimized this code by sliding window
// first Negative Number in every window of size k is the problem Statement
// If in a particular window if you will not get any negative number then insert 1 as a default value in absence of the negative number 
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int> arr = {2, 3, 4, 4, -7, -1, 4, -2, 6};
    int n = arr.size();
    // vector<int> ans;
    int k = 3;
    // int i1 = 0;
    // int j1 = k - 1;
    // while (j1 < n)
    // {
    //     for (int i = i1; i <= j1; i++)
    //     {
    //         if (arr[i] < 0)
    //         {
    //             ans.push_back(arr[i]);
    //             break;
    //         }
    //     }
    //     i1++;
    //     j1++;
    // }

    // Optimized by Sliding Window
    // Now this code is the optimized one by sliding window


    vector<int> ans(n - k + 1);
    int p = -1;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            p = i;
            break;
        }
    }
    if (p == -1)
        ans[0] = 1;
    else
        ans[0] = arr[p];
    int i = 1;
    int j = k;
    while (j < n)
    {
        if (p >= i)
            ans[i] = arr[p];
        else
        {
            p = -1;
            for (int x = i; x <= j; x++)
            {
                if (arr[x] < 0)
                {
                    p = x;
                    break;
                }
            }
            if (p != -1)
                ans[i] = arr[p];
            else
                ans[i] = 1;
        }
        i++;
        j++;
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "  ";
    }

    return 0;
}