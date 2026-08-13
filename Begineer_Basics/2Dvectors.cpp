#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n=4,m=3;
vector<vector<int>> v(n,vector<int>(m,-2));
v[2][1]=5;
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  cout<<v[i][j]<<"  ";
}
cout<<endl;
}

return 0;
}