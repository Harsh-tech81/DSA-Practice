//  Merge sort(Recursion ) is a sorting technique to sort a array better than previous sorting technique whose T.C. O(N^2)
// learn this code of the merge sort very well
// Merge sort for ascending order which is by default

#include <iostream>
#include <vector>
using namespace std;
void mergesort(vector<int> &a, vector<int> &b, vector<int> &res)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            res[k++] = a[i++];
        }
        else
        {
            res[k++] = b[j++];
        }
    }
    if (i == a.size())
    {
        while (j < b.size())
        {
            res[k++] = b[j++];
        }
    }
    if (j == b.size())
    {
        while (i < a.size())
        {
            res[k++] = a[i++];
        }
    }
}
void merge(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return;
    int n1 = n / 2;
    int n2 = n - n / 2;
    vector<int> app(n1);
    vector<int> ba(n2);
    // copy pasting
    for (int i = 0; i < n1; i++)
        app[i] = nums[i];
    for (int i = 0; i < n2; i++)
        ba[i] = nums[i + n1];
    // magic aka recursion
    merge(app);
    merge(ba);
    // merge
    mergesort(app, ba, nums);
    app.clear(); // clear the vectors in this way
    ba.clear();
}

int main()
{
    int arr[] = {-6, 8, 19, 67, 8, 12, 13, -56, -8};
    int n = sizeof(arr) / 4;
    vector<int> arr2(arr, arr + n); // same as array as a copy as a vector in the array (copy)
    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << "  ";
    cout << endl;

    merge(arr2);

    for (int i = 0; i < arr2.size(); i++)
        cout << arr2[i] << "  ";
    cout << endl;

    return 0;
}
