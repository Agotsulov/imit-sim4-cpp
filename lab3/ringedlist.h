#ifndef RINGEDLIST_H
#define RINGEDLIST_H

#include "list.h"
#include <string.h>


template <typename T>
class RingedList : public List<T> 
{
    public:
        RingedList();
        RingedList(RingedList<T> &other);
        RingedList(RingedList<T> &&other);
        ~RingedList();
        RingedList<T>& operator= (const List<T> &other);
        void operator= (const List<T> &&other);
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
void Iterator<T>::prev(){
    if(this->curr == 0x0) 
        this->curr = this->buff->prev;
    else 
        this->curr = this->curr->prev;
}

template <typename T>
T Iterator<T>::get(){
    if(this->curr != this->buff)
        return this->curr->value;
    else
        throw "List is empty";
}


template <typename T>
bool Iterator<T>::empty(){   
    if((this->curr == 0x0) || (this->curr == this->buff)) 
        return true;
    else 
        return false;
}

template <typename T>
RingedIterator<T>::~RingedIterator()
{
    //if(this->curr != this->buff) 
    //    delete this->curr;
    //delete this->buff;   
}

//ITERATOR END



template <typename T>
RingedList<T>::RingedList(){
    this->buff = new Data<T>;
    this->buff->value = 0;
    this->buff->next = 0x0;
    this->buff->prev = 0x0;
    this->length = 0;    
}

template <typename T>
RingedList<T>::RingedList(RingedList<T> &other){
    this->buff = new Data<T>;
    this->buff->value = 0;
    this->buff->next = 0x0;
    this->buff->prev = 0x0;
    this->length = 0;
    Iterator<T> i = other.iterator();
    Iterator<T> c = this->iterator();
    while(!i.empty()){
        this->insert(c, i.get());
        i.next();
        c.next();   
    }
    //this->length = other.length;

}


template <typename T>
RingedList<T>::RingedList(RingedList<T> &&other){
    this->buff = new Data<T>;
    this->buff->value = 0;
    this->buff->next = 0x0;
    this->buff->prev = 0x0;
    Iterator<T> i = other.iterator();
    Iterator<T> c = this->iterator();
    this->length = 0;
    while(!i.empty()){
        this->insert(c, i.get());
        i.next();
        c.next();   
    }
    //this->length = other.length;
    

    other.clear();
}

template <typename T>
RingedList<T>& RingedList<T>::operator=(const List<T> &other){
    RingedList r;
    Iterator<T> i = other.iterator();
    Iterator<T> c = r.iterator();
    while(!i.empty()){
        insert(c, i.get());
        i.next();
        c.next();   
    }
    r.length = other.length;

    return r;
}

template <typename T>
void RingedList<T>::operator=(const List<T> &&other){
    RingedList r = this;
    Iterator<T> i = other.iterator();
    Iterator<T> c = r.iterator();
    r.length = 0;
    while(!i.empty()){
        insert(c, i.get());
        i.next();
        c.next();   
    }

    other.clear();
}

template <typename T>
void List<T>::insert( Iterator<T> &pos,const T& value){
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
Iterator<T> List<T>::erase(Iterator<T> &pos){
    if(pos.pos() != this->buff){
        Data<T> *curr = pos.pos();

        Data<T> *n = curr->next;
        Data<T> *p = curr->prev;

        n->prev = p;
        p->next = n;

        delete curr;

        pos.prev();
    }
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
        i.next();
        if(i.get() == value) 
            return i;
    }
    throw "Not found";
}

template <typename T>
void List<T>::clear(){
    //Data<T>* test = this->buff;
    Iterator<T> i = iterator();
    while(!i.empty()){
        delete i.pos();
        i.next();
    }

    this->buff = new Data<T>;
    this->buff->value = 0;
    this->buff->next = 0x0;
    this->buff->prev = 0x0;
    this->length = 0;
}


template <typename T>
RingedList<T>::~RingedList(){
    Iterator<T> i = this->iterator();
    while(!i.empty()){
        delete i.pos();
        i.next();
    }

    delete this->buff;
}




#endif // RINGEDLIST_H
