// Brute Force approach of it (my personal approach )

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int Max = INT_MIN;
    int k = 4;
    int idxwindow = -1;
    for (int i = 0; i <= n - k; i++) // No. of possible windows
    {
         int currsum = 0;
        for (int j = i; j < i + k; j++)
        {
            currsum += arr[j];
        }
        if (Max < currsum)
        {
            Max = currsum;
            idxwindow = i;
        }
    }

    cout << Max<<endl<<idxwindow;
    return 0;
}


