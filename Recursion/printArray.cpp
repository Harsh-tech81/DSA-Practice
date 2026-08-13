#include <iostream>
#include <vector>
using namespace std;
void display(int arr[], int idx, int n)
{
    if (idx == n)
        return;
    cout << arr[idx] << "  ";
    display(arr, idx + 1, n);
}
void disvector(vector<int> &v, int idx)
{
    {
        if (idx == v.size())
            return;
        cout << v[idx] << "  ";
        disvector(v, idx + 1);
    }
}
int main()
{
    int arr[] = {2, 5, 6, 7, 8, 9, -6, 12};
    vector<int> v = {2, 5, 6, 7, 8, 9, -6, 12};
    int n = sizeof(arr) / 4;
    // display(arr, 0, n);
    disvector(v, 0);
    cout << endl;

    // Below is printed the elements of the array using forEach Loop
    // for(int ele:arr){
    //     cout<<ele<<"  ";
    // }
    return 0;
}