#include <bits/stdc++.h>
using namespace std;
// merge sort is not an inplace sorting algo where as the quick sort is inpalce sorting algo 
// In merge sort we require an extra O(N) space complexity to store the array copy 
// merge sort has O(NlogN) time comple in all the cases.
// 
void merge(vector<int> &v1, vector<int> &v2, vector<int> &ans) {
  int i = 0, j = 0, k = 0;
  int n = v1.size();
  int m = v2.size();
  while (i < n && j < m) {
    if (v1[i] <= v2[j]) {
      ans[k] = v1[i];
      i++;
    } else {
      ans[k] = v2[j];
      j++;
    }
    k++;
  }
  if (i == n) {
    for (int i = j; i < m; i++) {
      ans[k++] = v2[i];
    }
  }
  if (j == m) {
    for (int j = i; j < n; j++) {
      ans[k++] = v1[j];
    }
  }
}

void mergeSort(vector<int>&v){
   int i=0;
   int j=v.size()-1;

}

int main() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
     cin>>v[i];
  }
 cout<<endl;
 mergeSort(v);
 for(int i=0;i<n;i++) cin<<v[i]<<" ";
 cout<<endl;
  return 0;
}