#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max(int arr[], int n, int idx)
{
    if (n == idx)
        return INT_MIN;
    return max(arr[idx], max(arr, n, idx + 1));
}

void PrintMaxinArray(int arr[], int n, int idx, int max)
{
    if (n == idx)
    {
        cout << max << endl;
        return;
    }
    if (max < arr[idx])
        max = arr[idx];
    PrintMaxinArray(arr, n, idx + 1, max);
}

int main()
{
    int arr[] = {2, 5, 60, -78, 8, 9, -6, -12};
    int n = sizeof(arr) / 4;
    cout << max(arr, n, 0) << endl;
    // PrintMaxinArray(arr, n, 0, INT_MIN);
    return 0;
}