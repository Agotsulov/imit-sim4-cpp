#include <iostream>
#include "ringedlist.h"


int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;
    RingedList<int> r;
    Iterator<int> i = r.iterator();
    
    r.insert(i , 4);
    i.next();
    r.insert(i, -9);
   
    
    i.start();
    i.next();
    i.next();
    r.insert(i, 231);
    
    /*
    r.push_front(6);
    r.push_front(-12);
    r.push_front(12412);
    r.push_front(8);
    r.push_front(7);
    */
    
    
    i.start();
    do{
        std::cout << i.get() << std::endl;
        i.next();
    }while(!i.empty());
    
    return 0;
}
