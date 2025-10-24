#include <iostream>
#include <vector>
#include <set>

#include "modules/debugging.hpp"

using namespace std;

struct Cow {
    char direction;
    int xPos, yPos;
    int blame;
};

int main() {
	Cow cow1 = {'N', 0, 0, 0};
    Cow * subjectCow = &cow1;
    subjectCow -> blame = 2;
    cout << subjectCow -> direction << endl;
}