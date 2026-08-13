#include <iostream>
using namespace std;
int main()
{
   int m, n;
   cout << " Enter number of rows of matrix : ";
   cin >> m;
   cout << " Enter number of columns of matrix : ";
   cin >> n;
   cout << " Enter the Elements of matrix : " << endl;
   int arr[m][n];
   for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
         cin >> arr[i][j];
   for (int i = 0; i < m; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cout << arr[i][j] << "  ";
      }
      cout << endl;
   }
   cout << endl
        << endl;
   // Code for spiral matrix printing
   int maxr = m - 1;
   int maxc = n - 1;
   int minr = 0;
   int minc = 0;
   int count = 0;
   int tne = m * n; // Total number of elements
   while (count < tne)
   {
      // print the minimum row (Right)
      for (int j = minc; j <= maxc && count < tne; j++)
      {
         cout << arr[minr][j] << " ";
         count++;
      }
      minr++;
      // print the maximum column (down)
      for (int i = minr; i <= maxr && count < tne; i++)
      {
         cout << arr[i][maxc] << " ";
         count++;
      }
      maxc--;
      // print the maximum row (left)
      for (int j = maxc; j >= minc && count < tne; j--)
      {
         cout << arr[maxr][j] << " ";
         count++;
      }
      maxr--;
      // print the minimum column (up)
      for (int i = maxr; i >= minr && count < tne; i--)
      {
         cout << arr[i][minc] << " ";
         count++;
      }
      minc++;
   }

   return 0;
}
