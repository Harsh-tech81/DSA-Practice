#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int>nums={9};
vector<int>ans4;
int n=nums.size();
for(int i=0;i<n;i++){
    cout<<nums[i]<<"   ";
}
cout<<endl;
int ans =nums[0];
int i=0;
while(i<n-1){
    ans*=10;
ans+=nums[i+1];
i++;
}
int fans=ans+1;
cout<<fans;
cout<<endl;
while(fans>0){
    int ld=fans%10;
    fans/=10;
    ans4.push_back(ld);
}
int m=ans4.size();
int i1=0;
int j1=m-1;
while(i1<j1){
    swap(ans4[i1],ans4[j1]);
    i1++;
    j1--;
}

for(int i=0;i<m;i++){
    cout<<ans4[i]<<"   ";
}




    return 0;
}






