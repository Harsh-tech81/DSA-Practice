#include <iostream>
#include <string>
using namespace std;
// void remove(string ans, string ori)
// {
//     if (ori.length() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }
//     char ch = ori[0];
//     if (ch == 'a')
//         remove(ans, ori.substr(1));  // use of the substr function for printing the rest of the string from the index 1 to end of the string 
//     else
//         remove(ans + ch, ori.substr(1));
// }

void remove2withusingindex(string ans, string ori,int idx)
{
    if (idx == ori.length())
    {
        cout << ans << endl;
        return;
    }
    char ch = ori[idx];
    if (ch == 'h')
        remove2withusingindex(ans,ori,idx+1);  // use of the substr function for printing the rest of the string from the index 1 to end of the string 
    else
        remove2withusingindex(ans + ch,ori,idx+1);
}
int main()
{
    string s = "physics wallah";
    remove2withusingindex("", s,0);

    return 0;
}