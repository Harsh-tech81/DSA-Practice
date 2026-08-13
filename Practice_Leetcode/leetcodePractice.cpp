#include <bits/stdc++.h>
using namespace std;

int main() {
vector<vector<int>> events= {{1,3,2},{4,5,2},{2,4,3}};
sort(events.begin(),events.end());
for(auto el : events){
    for(int x: el){
        cout<<x<<"  ";
    }
    cout<<endl;
}
return 0;
}
