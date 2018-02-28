#include "../include/Iterator.h"

#include <iostream>


Iterator::Iterator(Queue &queue)
{
    this->q = &queue;
    start();
}

void Iterator::start(){
    index = q->getHead();
}

void Iterator::next(){
    index = (index + 1) % q->getSizeArray();
}

bool Iterator::finish(){
    return (index == q->getTail() - 1);
}

int Iterator::getValue(){
    return q->getArray()[index];
}

Iterator::~Iterator()
{
    q = 0;
    value = 0;
    index = 0;
}
