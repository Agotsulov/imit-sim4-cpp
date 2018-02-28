#include <iostream>
#include "Queue.h"
#include "Iterator.h"

using namespace std;

int main()
{
    Queue q(15);
    for(int i = 0; i < 10;i++)
        q.push(i);

    for(int i = 0; i < 3;i++)
        q.pop();
    for(int i = 0; i < 6;i++)
        q.push(i + 10);
    cout << "Head = " << q.getHead() << endl;
    cout << "Tail = " << q.getTail() << endl;
    Iterator i(q);
    i.finish();
    i.next();
    i.next();
    i.next();
    i.finish();
    i.getValue();
    i.start();
try{
    while(!i.finish()){
        cout << i.getValue() << endl;
        i.next();
    }
    cout << i.getValue() << endl;

}catch(char const *s){
    cout << "" << s << endl;
}
    return 0;
}
