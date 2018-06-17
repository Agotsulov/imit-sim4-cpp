#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include <string>

using namespace std;


int main(int argc, char **argv) {
    std::cout << "C++ is the worst programming language!" << std::endl;

    cout << "Скриншоты работоспособности программы внутри проекта" << endl;
    cout << "Screenshots of work inside the project" << endl;
    cout << "agrs -g main.cpp -o main -std=c++11" << endl;
    cout << "g++ (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4" << endl;

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

    BinaryTree copy(t); //Копируем. Конструкор перемещения аналогичен ,только в конце clear(); Далее док-во что clear работает

    cout << "Show t" << endl;
    t << cout; //В операторе<< есть строки которые для удобства можно раскоментить
    cout << endl;

    cout << "Show copy" << endl;
    copy << cout;
    cout << endl;

    cout << "CLEAR COPY" << endl; //Очищаем копию
    copy.clear();
    copy << cout;
    cout << endl;

    string search = "a";
    cout << "SEARCH " << search << " IN t" << endl;
    cout << "RESULT:" << t.search(search) << endl;
    
    cout << "COUNT WORDS IN t:" << t.size() << endl;

    cout << "DELETE a FROM t" << endl;
    t.remove("a");
    cout << "DELETE ab FROM t" << endl;
    t.remove("ab");
    t << cout;

    getchar(); //2018 год у Microsoft в VS code сам закрывается теринал...

    return 0;
}