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
    this->curr = first;
    this->start();
}

template <typename T>
void Iterator<T>::next(){
    if(this->curr == 0x0) 
        this->curr = this->buff->next;
    else 
        this->curr = this->curr->next;
}

template <typename T>
T Iterator<T>::get(){
    return this->curr->value;
}


template <typename T>
bool Iterator<T>::empty(){   
    if((this->curr == 0x0) || (this->curr->next == this->buff)) 
        return true;
    else 
        return false;
}

template <typename T>
RingedIterator<T>::~RingedIterator()
{
    if(this->curr != this->buff) 
        delete this->curr;
    delete this->buff;   
}

//ITERATOR END



template <typename T>
RingedList<T>::RingedList(){
    Data<T>* s = new Data<T>;
    this->buff = s;
    this->buff->value = 0;
    this->buff->next = 0x0;
    this->buff->prev = 0x0;
    this->length = 0;    
}


template <typename T>
void List<T>::insert( Iterator<T> pos,const T& value){
    /*
    Data<T> *curr = pos.pos();
    Data<T> *temp = new Data<T>;
    Data<T> *follow = 0x0;
    
    if(length == 0)
        curr = this->buff;
    else 
        curr = pos.pos();
    
    follow = curr->next;
    temp->value = value;
    temp->next = follow;
    temp->prev = curr;
    curr->next = temp;
    
    follow->prev = curr;
    */
    if(length == 0){
        Data<T> *curr = this->buff;
        Data<T> *temp = new Data<T>; //Почему так странно выделяет память?
        Data<T> *temp2 = new Data<T>;
      
        curr->next = temp2;
        temp2->value = value;
        temp2->next = curr;
        temp2->prev = curr;  
    
        curr->prev = temp2;
    } else {
        Data<T> *curr = pos.pos();
        Data<T> *temp = new Data<T>;
        Data<T> *p = 0x0;
    
        p = curr->next;
        temp->value = value;
        temp->next = p;
        temp->prev = curr;
        curr->next = temp;
    
        p->prev = temp;
 
        Data<T> *DEBUG = 0x0; //Иначе в дебагере не видно что в p
    }
    length++;
}

template <typename T>
Iterator<T> List<T>::erase( Iterator<T> pos){
    Data<T> *curr = pos.pos();

    Data<T> *n = curr->next;
    Data<T> *p = curr->prev;

    n->prev = p;
    p->next = n;

    delete curr;

    pos.next();
    
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
    do{
        i.next();
        if(i.get() == value) 
            return i;
    }while(!i.empty());
    throw "Not found";
}

template <typename T>
RingedList<T>::~RingedList(){
    delete this->buff;
}




#endif // RINGEDLIST_H
