#include <iostream>
#include <vector>
#include <set>

#include "modules/debugging.hpp"

using namespace std;

int main() {
	vector<int> arr{1, 2, 3, 4};
    set <int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(3);
	cout << arr << endl;  // just feed it into cout like any other variable
    cout << s << endl;
}