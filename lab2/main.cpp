#include <iostream>
#include "Queue.h"
#include "Iterator.h"

using namespace std;

int main()
{
try{
    Queue q(100);
    Iterator i(q);
    for(int i = 0; i < 5;i++)
        q.push(i);
    i.start();
    while(i.finish()){
        i.next();
        cout << i.getValue() << endl;
    }
}catch(char const *s){
    cout << "" << s << endl;
}
    return 0;
}
