#include <iostream>
#include <vector>
#include "BinaryTree.h"

using namespace std;

bool testSearch(){
    cout << "TEST SEARCH" << endl;
    
    BinaryTree<int> t(5);

    vector<bool> code = {1};
    
    t.insert(6,{1});
    t.insert(1,{0});

    if(code == t.search(6))
        return true;

    return false;
}

int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;

    BinaryTree<int> t(5);


    t.insert(3,{0});
    t.insert(8,{1});

    t.insert(10,{1,1});
    t.insert(7,{1,0});

    t.insert(4,{0,1});
    t.insert(1,{0,0});
    
    t << cout;

    cout << "Кол-во четных:" << t.countEven() << endl;

    cout << "Среднее арифметическое:" << t.arithmeticalMean() << endl; //Считает в том же типе

    cout << "Двоичное ли дерево:" << t.checkBinaryTree(1,10) << endl;

    if(testSearch())
        cout << "SUCCESS" << endl;

    cout << "TEST ALLPOSITIVE" << endl;
    if(t.allPositive())
        cout << "SUCCESS" << endl;

    cout << "TEST REMOVELEAFS" << endl;
    t.removeLeafs();

    t << cout;
    cout << "TEST REMOVELEAFS" << endl;
    t.removeLeafs();

    t << cout;

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}