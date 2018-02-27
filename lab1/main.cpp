#include <iostream>
#include <string>
#include "include/Vector.h"

using namespace std;

int main()
{
    cout << endl << "ТЕСТ:Создание" << endl;

    Vector v(10,3);
    cout << v[0] << endl;

    cout << endl << "ТЕСТ:Resize" << endl;
    v.resize(15);

    cout << v[0] << endl;
    cout << v[13] << endl;

    cout << endl << "ТЕСТ:Копировние и вывод" << endl;
    Vector v1(5,41);
    Vector v2(v1);

    v1 << cout;
    cout << endl;
    v2 << cout;

    cout << endl << "ТЕСТ:Перемещение и вывод" << endl;
    Vector mig1(7,12);
    Vector mig2(move(mig1));

    mig1 << cout;
    //cout << mig1[1] << endl;
    cout << endl;
    mig2 << cout;


    cout << endl <<"ТЕСТ:Операторы сравниения" << endl;
    Vector compare_first(10,3);
    Vector compare_second(compare_first);

    if(compare_first == compare_second) cout << "Конструктор копирования ==" << endl;

    compare_first = compare_second;
    if(compare_first == compare_second) cout << "оператор =  ==" << endl;

    compare_first = move(compare_second);
    Vector compare_third(10,5);
    if(compare_third != compare_first) cout << "!=" << endl;

    Vector more_first(10,4);
    if(more_first > compare_first) cout << ">" << endl;

    cout << endl << "ТЕСТ:Исключение" << endl;

    Vector v4(154,4);

    try{
        if(v4 == v1) cout << "Где исключение?" << endl;
    }catch(char const *s){
        cout << "!!! " << s << endl;
    }


    cout << endl << "ТЕСТ:Резерв" << endl;
    Vector v5(10,14);
    v5.reserve(20);
    cout << "v5[-1] = " << v5[-1] << endl;
    cout << "v5[10000] = " << v5[10000] << endl;
    cout << "v5[9] = " << v5[9] << endl;
    cout << "v5[19] = " << v5[19] << endl;


    cout << endl << "ТЕСТ:Push & pop" << endl;
    Vector p(5,14);
    cout << p.popBack() << endl;
    p.pushBack(333);
    p.pushBack(223);
    cout << p.popBack() << endl;
    cout << p.popBack() << endl;
    cout << p.popBack() << endl;
    cout << p.popBack() << endl;

    cout << endl << "TEST PEREMEHSENIA =" << endl;
    Vector per1(10,10);
    Vector per2(move(per1));

    cout << "per1 = ";
    per1 << cout;
    cout << "per2 = ";
    per2 << cout;

    cout << endl;
    per1 = move(per2);

    cout << "per1 = ";
    per1 << cout;
    cout << "per2 = ";
    per2 << cout;

    return 0;
}
