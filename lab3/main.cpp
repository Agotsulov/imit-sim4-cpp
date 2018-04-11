#include <iostream>
#include "ringedlist.h"


int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;
    RingedList<int> r;
    Iterator<int> i = r.iterator();
    
    //r.insert(i , 4);
    //i.next();
    //r.insert(i, -9);
    
    r.push_front(6);
    r.push_front(-12);
    r.push_front(12412);
    r.push_front(8);
    r.push_front(7);
    
    i.start();
    while(!i.empty()){
        std::cout << i.get() << std::endl;
        i.next();
    }
    
    i.start();
    
    for(int d = 0;d < 5;d++){
    
        std::cout << i.get() << std::endl;
        i.next();
        
    }
    
    return 0;
}
