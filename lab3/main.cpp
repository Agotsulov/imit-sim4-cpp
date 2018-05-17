#include <iostream>
#include <cstdio>
#include <stdlib.h>
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
    r.insert(i, 231);
    
    i.next();
    r.insert(i, 200000);

    i.next();
    r.insert(i, 1231);

    i.next();
    r.insert(i, 991231);
    
    i.next();
    r.erase(i);
    //r.erase(i);

    i.next();
    r.insert(i, 11);
    i.next();
    
    i.next();
    r.insert(i, 322);
     
    i.start();
    do{
        i.next();
        std::cout << i.get() << std::endl;
    }while(!i.empty());
    
    std::cout << "Search = " << r.search(200000).get() << std::endl;
    

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}
