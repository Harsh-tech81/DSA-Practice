// Sliding Window
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    vector<int> arr = {7, 1, 2, 5, 8, 4, 9, 3, 6};
    int n = arr.size();
    int MaxSum = INT_MIN;
    int currSum = 0;
    int maxIdx = -1;
    int k = 4;
    for (int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }
    MaxSum = currSum;
    int i = 1;
    int j = k;
    while (j < n)
    {
        currSum += arr[j] - arr[i - 1];
        if (MaxSum < currSum)
        {
            MaxSum = currSum;
            maxIdx = i;
        }
        i++;
        j++;
    }

    cout << MaxSum << endl
         << maxIdx;

    return 0;
}