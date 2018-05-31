#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "linkedhashmap.h"

using namespace std;

int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;

    LinkedHashMap<char,int> map(10);

    /*
    char c = 'b';
    do{
        cin >> c;
        cout << (int) c << endl;
    }while(c != 'a');
    */
   
    map.put('a',3);
    map.put('b',4);
    map.put('u',6);
    map.put('v',5);

    cout << map.get('a') << endl;    
    cout << map.get('b') << endl;
    cout << map.get('u') << endl;
    cout << map.get('v') << endl;

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}
