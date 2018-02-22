#include "RingBuffer.h"

RingBuffer::RingBuffer(int size) : Vector(size){
    indexEnd = 0;
    indexBegin = 0;
}

void RingBuffer::push(int value){
    if(length() <= 0) throw "Empty";
    this->pushBack(value);
}

int RingBuffer::pop(){
    if(indexEnd < length()) throw "OutOfRange";
    int result = this[indexEnd];
    indexEnd++;
    return result;
}

int RingBuffer::get(){
    if(length() <= 0) throw "Empty";
    return this[length() - 1];
}


bool RingBuffer::empty(){
    if(length() == 0) return true;
    return false;
}

void RingBuffer::makeEmpty(){
    resize(0);
}

int RingBuffer::length(){
    return this->Vector::length();
}

RingBuffer::~RingBuffer()
{
    this->~Vector();
}
