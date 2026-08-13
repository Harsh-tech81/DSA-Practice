#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 8, 9};
//   cout << l.size() << endl;
  l.push_back(12);
  l.push_front(13);
  l.pop_back();
  l.pop_front();
//   l.remove(8);
  // l.erase(3);
  for (int el : l)
    cout << el << " ";

  return 0;
}