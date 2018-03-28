#ifndef LIST_H
#define LIST_H

#include "iterator.h"

template <typename T>
class List
{
    public:

        virtual void insert( Iterator<T> pos, const T& value ); 
        virtual void insert( Data<T>* pos, const T& value ); 
        
        virtual Iterator<T> erase( Iterator<T> pos );
        virtual Data<T>* erase( Data<T>* pos );
        
        virtual Iterator<T> search(const T& value);
//        void push_front(const T& value);
//        T pop_front();
//        void push_back(const T& value);
//        T pop_back();
        void clear();
        bool empty();
        int size();
        virtual Iterator<T> iterator();
    protected:
        Data<T>* buff;
        //Data<T>* head;
        int length;
    private:
};

template<typename T>
bool List<T>::empty(){  
    if(length <= 0) 
        return false;
    else 
        return true;
}

template <typename T>
void List<T>::clear(){
    this->buff = 0x0;
}


template<typename T>
int List<T>::size(){
    return length;
}

#endif // LIST_H
