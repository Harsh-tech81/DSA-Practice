#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(6);
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    // s.insert(1);  // contains or display only unique element

    // for(int val : s) cout<<val<<"  ";
    cout<<s.size()<<endl;
    for(int val : s) cout<<val<<"  ";
    s.clear();
    cout<<endl;
     for(int val : s) cout<<val<<"  ";
      cout<<s.size();
    // cout<<endl;
    // cout<<s.size()<<endl;
    // s.erase(6);
    // cout<<s.size()<<endl;

    // For displaying the elements of the set we use ForEach Loop int can be replaced by auto it automatically decides the datatype either int in set or pair in map
    // for (auto val : s)
    //     cout << val << "  "; // 1  2  6  5  4  3   in random fashion
    // cout << endl;
    // // For searching any element in the set
    // // s.find()--> it searches in the set and if,it is not found then it returns the last element
    // int target = 54;
    // if (s.find(target) != s.end())
    // { // target exists
    //     cout << "Exists" << endl;
    // }
    // else
    //     cout << "Doesn't Exist" << endl;


        
    return 0;
}