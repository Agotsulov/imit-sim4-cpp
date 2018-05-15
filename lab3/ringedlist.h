#ifndef RINGEDLIST_H
#define RINGEDLIST_H

#include "list.h"

template <typename T>
class RingedList : public List<T> 
{
    public:
        RingedList();
        ~RingedList();
    private:
    protected:
        
};

template <typename T>
class RingedIterator : public Iterator<T>
{
    public:
        RingedIterator(Data<T>* first);
        ~RingedIterator();
    protected:
    private:
};

template<typename T>
RingedIterator<T>::RingedIterator(Data<T>* first)
{
    this->buff = first;
    this->start();
}

template <typename T>
void Iterator<T>::next(){
    this->curr = this->curr->next;
}

template <typename T>
T Iterator<T>::get(){
    return this->curr->value;
}


template <typename T>
bool Iterator<T>::empty(){   
    if((this->curr == 0x0) || (this->curr == this->buff->next)) 
        return true;
    else 
        return false;
}

template <typename T>
RingedIterator<T>::~RingedIterator()
{
    delete this->buff;
    delete this->curr;
}

//ITERATOR END



template <typename T>
RingedList<T>::RingedList(){
    Data<T>* s = new Data<T>;
    this->buff = s;
    this->buff->value = 0;
    this->buff->next = new Data<T>;
    this->buff->prev = new Data<T>;
    this->length = 0;    
}


template <typename T>
void List<T>::insert( Iterator<T> pos,const T& value){
    if(length == 0){
        Data<T> *curr = this->buff;
        Data<T> *temp = new Data<T>;
        Data<T> *p = 0x0;
    
        p = curr->next;
        curr->next = temp;
        temp->value = value;
        temp->next = p;
        temp->prev = curr;  
    
        p->prev = temp; 
    } else {
        Data<T> *curr = pos.pos();
        Data<T> *temp = new Data<T>;
        Data<T> *p = 0x0;
    
        p = curr->next;
        curr->next = temp;
        temp->value = value;
        temp->next = p;
        temp->prev = curr;  
    
        p->prev = temp;  
    }
    length++;
}

template <typename T>
void List<T>::push_front( const T& value){
    length++;
    if(this->buff->next == 0x0){
        Data<T> * n = new Data<T>;
        n->value = value;
        this->buff->next = n;
        this->buff->prev = n;
        n->prev = this->buff->next;
        n->next = this->buff->prev;
    } else {
        Data<T> * n = new Data<T>;
        Data<T> * p = this->buff->next;
        n->value = value;
        n->prev = p;
        n->next = this->buff->prev;
        p->next = n;    
        this->buff->next = n;
    }
}

template <typename T>
void List<T>::push_back( const T& value){
    length++;
    Data<T> * n = new Data<T>;
    n->value = value;
    n->prev = this->buff->next;
    n->next = this->buff->prev;
    this->buff->prev = n;
    n->next->prev = n;    
}


template <typename T>
Iterator<T> List<T>::erase( Iterator<T> pos){
    return pos;
}

template <typename T>
Iterator<T> List<T>::iterator(){
    RingedIterator<T> i(this->buff);
    return i;
}


template <typename T>
Iterator<T> List<T>::search(const T& value){
    Iterator<T> i = iterator();
    while(!i.empty()){
        if(i.get() == value) return i;
        i.next();
    }
    throw "Not found";
}

template <typename T>
RingedList<T>::~RingedList(){
    delete this->buff;
}




#endif // RINGEDLIST_H
