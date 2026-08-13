// Total number of Inversions Brute force approach 
// Most optimized approach is done by using merge sorting algorithm 

#include<iostream>
#include<vector>
using namespace std;

int Inversions(vector<int>&a,vector<int>&b){
int c=0;
int i=0;
int j=0;
while(i<a.size() && j<b.size()){
if(a[i]>b[j]){
c+=(a.size()-i);
j++;
}
else i++;

}

    return c;
}
void mergesort(vector<int>&a,vector<int>&b,vector<int>&res){
    int i=0;
    int j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            res[k++]=a[i++];
        }
        else{
            res[k++]=b[j++];
        }
    }
if(i==a.size()){
    while(j<b.size()){
        res[k++]=b[j++];
    }
}
if(j==b.size()){
    while(i<a.size()){
       res[k++]=a[i++];
    }
}

}
int merge(vector<int>&nums){
    int count=0;
int n=nums.size(); 
if(n==1) return 0;
int n1=n/2;
int n2=n-n/2;
vector<int>app(n1);
vector<int>ba(n2);
// copy pasting 
for(int i=0;i<n1;i++) app[i]=nums[i];
for(int i=0;i<n2;i++) ba[i]=nums[i+n1];
// magic aka recursion
count+=merge(app);
count+=merge(ba);
// Count the Inversions 
count+=Inversions(app,ba);
// merge 
mergesort(app,ba,nums);
app.clear();
ba.clear();
return count;

}

int main(){
vector<int>nums={5,1,3,0,4,9,6};
// int count=0;
// int n=nums.size();
// for(int i=0;i<n-1;i++){
// for(int j=i+1;j<n;j++){
//     if(nums[i]>nums[j]) count++;
// }    
// }
// cout<<count;
for(int val:nums) cout<<val<<"  ";
cout<<endl<<endl;
cout<<merge(nums);

// for(int val:nums) cout<<val<<"  ";

return 0;
}