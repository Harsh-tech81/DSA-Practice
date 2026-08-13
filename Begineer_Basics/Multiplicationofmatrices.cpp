
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int m;
  cout << " Enter number of rows of 1st matrix : ";
  cin >> m;
  int n;
  cout << " Enter number of columns of 1st matrix : ";
  cin >> n;
  int p;
  cout << " Enter number of rows of 2nd matrix : ";
  cin >> p;
  int q;
  cout << " Enter number of columns of 2nd matrix : ";
  cin >> q;
  if (n == p)
  {
    int a[m][n];
    int b[p][q];
    cout << " Enter the Elements of 1st matrix : " << endl;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];
    cout << " Enter the Elements of 2nd matrix : " << endl;
    for (int i = 0; i < p; i++)
      for (int j = 0; j < q; j++)
        cin >> b[i][j];
    cout << " The product of these two matrices are  : \n";
    int res[m][q];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < q; j++)
      {
        res[i][j] = 0;
        for (int k = 0; k < n; k++)
        {
          res[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < q; j++)
      {
        cout << res[i][j] << " ";
      }
      printf("\n");
    }
  }
  else
  {
    cout << " Matrix Multiplication is not possible ";
  }

  return 0;
}