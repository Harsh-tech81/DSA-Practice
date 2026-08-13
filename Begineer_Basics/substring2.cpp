#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> getAllSubstrings(const string &str)
{
    vector<string> substrings;
    int n = str.length();

    // Generate all substrings
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string substring = str.substr(i, j - i + 1);
            substrings.push_back(substring);
        }
    }

    return substrings;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    vector<string> substrings = getAllSubstrings(input);

    cout << "All substrings of \"" << input << "\":" << endl;
    for (const string &s : substrings)
    {
        cout << s << endl;
    }

    cout << "Total number of substrings: " << substrings.size() << endl;

    return 0;
}