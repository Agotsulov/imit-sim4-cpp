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
    r.erase(i);

    i.next();
    r.insert(i, 11);
    i.next();
    
    i.next();
    r.insert(i, 322);
     
    i.start();
    while(!i.empty()){
        std::cout << i.get() << std::endl;

        i.next();
    }
    
    std::cout << "ABABABABA" << std::endl;

    //std::cout << "Search = " << r.search(200000).get() << std::endl;
    
    r.clear();
    i = r.iterator();
    
    r.insert(i, 1);
    i.next();
    r.insert(i, 3);
    r.insert(i, 2);
    

    std::cout << std::endl << "After clear" << std::endl;

    i.start();
    while(!i.empty()){
        std::cout << i.get() << std::endl;
        i.next();
    }


    std::cout << "copy" << std::endl;

    RingedList<int> r2(r);
    Iterator<int> i2 = r2.iterator(); 
    i2.start();
    while(!i2.empty()){
        std::cout << i2.get() << std::endl;
        i2.next();
    }
    std::cout << "move" << std::endl;

    RingedList<int> r3(std::move(r));
    Iterator<int> i3 = r3.iterator(); 
    i3.start();
    while(!i3.empty()){
        std::cout << i3.get() << std::endl;
        i3.next();
    }



    std::cout << "check" << std::endl;
    i = r.iterator();
    i.start();
    while(!i.empty()){
        std::cout << i.get() << std::endl;

        i.next();
    }
    

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}
