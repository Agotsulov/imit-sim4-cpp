#ifndef RINGEDLIST_H
#define RINGEDLIST_H

#include "list.h"

template <typename T>
class RingedList : public List<T> 
{
    public:
        RingedList();
        //void insert( Iterator pos, const T& value ); 
        //void erase( Iterator pos );
        //Iterator search(const T& value);
        //void clear();
        //Iterator iterator();
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
    this->begin = first;
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
    if(this->curr == this->begin)
        return true;
    else 
        return false;
}

template <typename T>
RingedIterator<T>::~RingedIterator()
{
    this->begin = 0;
    this->curr = 0;
}



//ITERATOR END


template <typename T>
RingedList<T>::RingedList(){
    Data<T>* d;
    this->buff = d;
}

template <typename T>
void List<T>::insert( Data<T>* pos,const T& value){
    length++;
    Data<T>* p;
    Data<T>* n;
    n = pos->next; 
    pos->next = p; 
    p->value = value;
    p->next = n; 
    p->prev = pos;
    n->prev = p;
}

template <typename T>
void List<T>::insert( Iterator<T> pos,const T& value){
    length++;
    Data<T>* p;
    Data<T>* n;
    Data<T>* c = pos.pos();
    n = c->next; 
    c->next = p; 
    p->value = value;
    p->next = n; 
    p->prev = c;
    n->prev = p;    
}



template <typename T>
Data<T>* List<T>::erase( Data<T>* pos){
    length--;
    Data<T>* p;
    Data<T>* n;
    p = pos->prev;
    n = pos->next; 
    p->next = pos->next; 
    n->prev = pos->prev; 
    return pos;
}

template <typename T>
Iterator<T> List<T>::erase( Iterator<T> pos){
    this->erase(pos.pos());
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
    this->buff = 0x0;
}




#endif // RINGEDLIST_H
