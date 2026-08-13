// Basic Question of the two stairs only two case either 1 or 2 jump
#include <iostream>
using namespace std;
int stair(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return stair(n - 1) + stair(n - 2);
}
int main()
{
    cout << stair(5) << endl;

    return 0;
}

// Below code is more modified in which 1 or 2 or 3 jump possible in which calculate how many possible cases is possible

// #include<iostream>
// using namespace std;
// int stair(int n){
//     if(n==1) return 1;
//     if(n==2) return 2;
//     if(n==3) return 4;
//     return stair(n-1) + stair(n-2)+stair(n-3);

// }
// int main(){
// cout<<stair(5)<<endl;

//     return 0;
// }