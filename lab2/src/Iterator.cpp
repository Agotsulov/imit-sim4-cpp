#include "../include/Iterator.h"

Iterator::Iterator(Queue &queue)
{
    q = queue;
    start();
}

void Iterator::start(){
    index = 0;
    value = 0;
}

void Iterator::next(){
    index++;
    value = q.pop();
}

bool Iterator::finish(){
    return (q.size() == 0);
}

int Iterator::getValue(){
    return value;
}

Iterator::~Iterator()
{
    q = 0;
    value = 0;
    index = 0;
}
