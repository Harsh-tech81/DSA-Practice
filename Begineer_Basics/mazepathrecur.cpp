#include<iostream>
using namespace std;
// Using 4 parameters 
int maze(int sr,int sc,int er,int ec){
if(sr>er || sc>ec) return 0;
if(sr==er && sc==ec) return 1;
int rightways=maze(sr,sc+1,er,ec);
int leftways=maze(sr+1,sc,er,ec);
int totalways=rightways+leftways;
return totalways;
}
// Printing different ways of moving on the maze path using 4 parameters 
void printpath(int sr,int sc,int er,int ec,string s){
if(sr>er || sc>ec) return;
if(sr==er && sc==ec){  // Destination Reached 
cout<<s<<endl;
return;
} 
printpath(sr,sc+1,er,ec,s+'R'); // Right
printpath(sr+1,sc,er,ec,s+'D');  //Down
}
// Using 2 parameters only 
int maze2(int row,int col){
if(row<1 || col<1) return 0;
if(row==1 && col==1) return 1;
int rightWays=maze2(row,col-1);
int downWays=maze2(row-1,col);
int totalways=rightWays+downWays;
return totalways;
}
// Printing different ways of moving on the maze path using 2 parameters 
void printpath2(int row,int col,string s){
if(row<1 || col<1) return;
if(row==1 && col==1){  // Destination Reached 
cout<<s<<endl;
return;
} 
printpath2(row,col-1,s+'R'); // Right
printpath2(row-1,col,s+'D');  //Down
}
int main(){
// cout<<maze(1,1,3,3);
// printpath(0,0,2,2,"");
// cout<<maze2(3,3);
printpath2(3,3,"");

return 0;
}