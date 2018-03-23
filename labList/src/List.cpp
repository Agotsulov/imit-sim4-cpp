#include "../include/List.h"

template <typename T>
List<T>::List()
{
    Data d;
    d.next = this->back;
    this->front = d;
    this.length = 0;
}

template <typename T>
void List<T>::push(const T value){
    length++;
    this->back.value = value;
    Data d;
    this->back.next = d;
}

template <typename T>
List<T>::~List()
{
    //dtor
}
