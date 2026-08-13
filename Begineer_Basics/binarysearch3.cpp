// 

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
vector<int>nums={0,1,2,3,4,7};
int n=nums.size();
int st=0;
int end=n-1;
while(st<=end){
 int mid=st+(end-st)/2;
if(mid==nums[mid]) st=mid+1;
else {
  ans=mid;
  end=mid-1;
}
}

cout<<ans;







return 0;
}