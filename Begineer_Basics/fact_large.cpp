class Solution {
  public:
  void multiply(vector<int>&arr,int &size,int k){
      int carry=0;
      for(int i=0;i<size;i++){
int res=k*arr[i];
          res+=carry;
          arr[i]=res%10;
          carry=res/10;
           }
      // carry 12
      while(carry>0){
          arr[size]=carry%10;
          size++;
          carry/=10;
        
      }
      
  }
    
    vector<int> factorial(int n) {
    vector<int>arr(10000,0);
    arr[0]=1;
    int size=1;
for(int i=2;i<=n;i++){
    multiply(arr,size,i);
}
    
vector<int>ans;
    for(int i=size-1;i>=0;i--){
        ans.push_back(arr[i]);
}

return ans;

    }
};