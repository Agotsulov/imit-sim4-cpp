#include <iostream>
#include "include/List.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    List<int> l;

    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);

    cout << l.pop(0) << endl;
    cout << l.pop(1) << endl;
    cout << l.pop(2) << endl;
    cout << l.pop(3) << endl;
    cout << l.pop(4) << endl;

    return 0;
}
