// Maze Path
#include <iostream>
using namespace std;

int maze(int sr, int sc, int er, int ec)
{
    if (sr > er || sc > ec)
        return 0;
    if (sr == er && sc == ec)
        return 1;
    int rightWays = maze(sr, sc + 1, er, ec);
    int leftWays = maze(sr + 1, sc, er, ec);
    int totalWays = rightWays + leftWays;
    return totalWays;
}
int maze2(int er, int ec)
{
    if (1 > er || 1 > ec)
        return 0;
    if (1 == er && 1 == ec)
        return 1;
    int rightWays = maze2( er, ec-1);
    int leftWays = maze2(er-1, ec);
    int totalWays = rightWays + leftWays;
    return totalWays;
}
void printPath(int sr, int sc, int er, int ec, string s)
{
    if (sr > er || sc > ec)
        return;
    if (sr == er && sc == ec)
    { // Destination reached
        cout << s << endl;
        return;
    }

    printPath(sr, sc + 1, er, ec, s + 'R'); // Right
    printPath(sr + 1, sc, er, ec, s + 'D'); // Down
}
void printPath2( int er, int ec, string s)
{
    if (1 > er || 1 > ec)
        return;
    if (1 == er && 1 == ec)
    { // Destination reached
        cout << s << endl;
        return;
    }

    printPath2( er, ec-1, s + 'R'); // Right
    printPath2(er-1, ec, s + 'D'); // Down
}

// We have solved by using 2 or 4 parameters 
int main()
{
    // cout << maze(1, 1, 3, 3) << endl;
    // cout << maze2(3, 3) << endl;
    printPath(1, 1, 3, 3, ""); 
    cout<<endl;
    printPath2(3, 3, "");
    return 0;
}