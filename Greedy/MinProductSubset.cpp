#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int MinProdSubset(vector<int> &arr)
{
    int n = arr.size();
    int cn = 0, cz = 0; // count of negatives and count of zeroes
    for (int ele : arr)
    {
        if (ele == 0)
            cz++;
        else if (ele < 0)
            cn++;
    }
    if (cn == 0)
    {
        if (cz == 0)
        {
            sort(arr.begin(), arr.end());
            return arr[0];
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int store, pro = 1;
        int pro1 = 1;
        if (cn % 2 == 0)
        { // even number of negatives
            sort(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i + 1] >= 0 && arr[i] < 0)
                {
                    store = arr[i];
                    break;
                }
            }
            for (int ele : arr)
            {
                if (ele != 0)
                    pro1 *= ele;
            }
            return pro1 / store;
        }
        else
        { // odd number of negatives
            for (int ele : arr)
            {
                if (ele != 0)
                    pro *= ele;
            }
            return pro;
        }
    }
}
int main()
{
    vector<int> v = {12,4,9,8,45};
    cout << MinProdSubset(v);
    return 0;
}