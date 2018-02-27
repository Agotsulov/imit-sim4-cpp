#include "../include/Queue.h"

Queue::Queue()
{
    sizeArray = 10;
    array = new int[sizeArray];
    head = 0;
    tail = 0;
}

Queue::Queue(int size)
{
    sizeArray = size;
    array = new int[sizeArray];
    head = 0;
    tail = 0;
}

int Queue::size(){
    if(head > tail)
        return (sizeArray - head + tail);
    else
        return (tail - head);
}

void Queue::push(int value){
    if(size() != sizeArray - 1){
        array[tail] = value;
        tail = (tail + 1) % sizeArray;
    } else
        throw "Нет места в очереди";
}

int Queue::pop(){
    if(isEmpty())
        throw "Очередь пуста";
    int result = array[head];
    head = (head + 1) % sizeArray;
    return result;
}

int Queue::get(){
    if(isEmpty())
        throw "Очередь пуста";
    return array[head];
}

bool Queue::isEmpty(){
    return (head == tail);
}

void Queue::empty(){
    head = tail;
}

Queue::~Queue()
{
    sizeArray = 0;
    head = 0;
    tail = 0;
    delete array;
}
