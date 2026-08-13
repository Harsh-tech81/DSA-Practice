#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={4,3,2,1,5,6,7};
    vector<int>vec(2);
    int n=arr.size();
    int target=6;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
if(arr[i] + arr[j] ==target){
vec[0]=i;
vec[1]=j;
};
    }

    }

for(int val : vec) cout<<val<<"  ";
    return 0;
}