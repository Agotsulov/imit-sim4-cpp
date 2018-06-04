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

    cout << "TEST PUT AND GET" << endl;

    map.put('a',3);
    map.put('b',4);
    map.put('u',6);
    map.put('v',5);

    cout << map.get('a') << endl;    
    cout << map.get('b') << endl;
    cout << map.get('u') << endl;
    cout << map.get('v') << endl;

    
    cout << "TEST REMOVE" << endl;

    map.remove('a');
    map.remove('v');
        
    cout << map.get('b') << endl;
    cout << map.get('u') << endl;

    try{
        cout << map.get('a') << endl;
    } catch (const char *error){
        cout << error << endl;
    }
    try{
        cout << map.get('v') << endl;
    } catch (const char *error){
        cout << error << endl;
    }
    
    cout << "TEST ITERATOR" << endl;

    map.put('f',0);
    map.put('z',3);
    map.put('d',-12);
    map.put('x',100);

    Iterator<int,char> iterator = map.iterator();

    while(!iterator.isEmpty()){
        cout << iterator.get() << endl;
        iterator.next();
    }

    cout << "TEST SEARCH" << endl;

    int found = 3;
    try{
        cout << "Найти value = " << found << " key = " << map.search(3) << endl;
    } catch (const char *error){
        cout << error << endl;
    }
    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}
