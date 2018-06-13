#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include <string>

using namespace std;


int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;

    BinaryTree t("a");


    t.insert("a");
    t.insert("b");
    t.insert("c");
    t.insert("d");
    t.insert("f");
    t.insert("x");
    t.insert("g");
    t.insert("l");

    t.insert("afa");
    t.insert("afa");

    t.insert("ab");
    t.insert("aa");

    t.insert("a");
    t.insert("a");
    t.insert("a");
    t.insert("a");
    t.insert("a");
    t.insert("a");


    BinaryTree copy(t);
    

    cout << "Вывод" << endl;
    t << cout;
    cout << endl;

    cout << "TEST COPY" << endl;
    copy << cout;
    cout << endl;

    cout << "CLEAR COPY" << endl;
    copy.clear();
    copy << cout;
    cout << endl;

    string search = "a";
    cout << "Search = " << search << endl;
    cout << "count:" << t.search(search) << endl;
    
    cout << "Общее кол-во слов с учетом вхождений:" << t.size() << endl;

    cout << "DELETE" << endl;
    t.remove("a");
    t.remove("ab");
    t << cout;

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}