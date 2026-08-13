#include <climits>
#include <iostream>

using namespace std;
int main() {
  int m, n;
  cout << " Enter Number of Rows : ";
  cin >> m;
  cout << " Enter Number of Columns : ";
  cin >> n;
  int arr[m][n];
  int brr[n][m]; // Interchanging the rows and columns of the original matrix
  cout << " Enter elements of the Matrices : ";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
  cout << endl;
  cout << " Transpose of the Given Matrix : " << endl;
  // Transpose of the matrix calculate Code
  // 1. --> by changing the original array
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[j][i] << "  ";
    }
    cout << endl;
  }
  // By taking New array called transpose array to print the elements
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      brr[i][j] = arr[j][i];
    }
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << brr[i][j] << "  ";
    }
    cout << endl;
  }

  return 0;
}