#include <iostream>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
void heapify(int i, int arr[], int n)
{
       while (1)
        {
            int l = 2 * i, r = 2 * i + 1;
            if (l >=n)
                break;
            if (r >=n)
            {
                if (arr[i] < arr[l])
                {
                    swap(arr[i], arr[l]);
                    i = l;
                }
                break;
            }
            if (arr[l] < arr[r])
            {
                if (arr[i] < arr[r])
                {
                    swap(arr[i], arr[r]);
                    i = r;
                }
                else
                    break;
            }
            else
            {
                if (arr[i] < arr[l])
                {
                    swap(arr[i], arr[l]);
                    i = l;
                }
                else
                    break;
            }
        }
}
int main()
{
    int arr[] = {-1, 10, 2, 14, 11, 1, 4}; // we have adding one extra element in the array which is -1 for increase the index or start the index from the 1
    int n = sizeof(arr) / 4;
    print(arr, n);
    for (int i = n / 2; i >= 1; i--)   // maxHeap me convert kiya h 
    {
        heapify(i, arr, n);
    }
    print(arr, n);

    return 0;
}