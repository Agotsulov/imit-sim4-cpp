#include <iostream>
#include <vector>
#include "BinaryTree.h"

using namespace std;


int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;

    BinaryTree<int> t(5);


    t.insert(3,{0});
    t.insert(8,{1});

    t.insert(10,{1,1});
    t.insert(7,{1,0});

    t.insert(4,{0,1});
    t.insert(1,{0,0});


    BinaryTree<int> copy(t);

    cout << "Вывод" << endl;
    t << cout;

    cout << "Вывод" << endl;
    t.show(cout);

    cout << "TEST COPY" << endl;
    copy << cout;

    cout << "CLEAR COPY" << endl;
    copy.clear();
    copy << cout;


    cout << "Кол-во четных:" << t.countEven() << endl;

    cout << "Среднее арифметическое:" << t.arithmeticalMean() << endl; //Считает в том же типе

    cout << "Двоичное ли дерево:" << t.checkBinaryTree(1,10) << endl;

    int search = 4;
    cout << "Search = " << search << endl;
    cout << "Path:";
    vector<bool> path;
    path = t.search(4);
    for(int i = 0;i < path.size();i++)
        cout << " " << path[i] << " " ;
    cout << endl;

    cout << "TEST ALLPOSITIVE:";
    cout << t.allPositive() << endl;

    cout << "REMOVELEAFS" << endl;
    t.removeLeafs();

    cout << "Вывод" << endl;
    t << cout;
    cout << "REMOVELEAFS" << endl;
    t.removeLeafs();

    cout << "Вывод" << endl;
    t << cout;

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}