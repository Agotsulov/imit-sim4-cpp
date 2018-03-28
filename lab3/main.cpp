#include <iostream>
#include "ringedlist.h"


int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    RingedList<int> r;
    Iterator<int> i = r.iterator();
    r.insert(i , 4);
    return 0;
}
