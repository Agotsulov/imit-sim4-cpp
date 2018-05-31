#ifndef LINKEDHASHMAP_H
#define LINKEDHASHMAP_H

#include "hashmap.h"

template <typename T>
class LinkedIterator : public Iterator<T>
{
    public:
        LinkedIterator(Data<T> *first);
        ~LinkedIterator();
};

template <typename K, typename V>
class LinkedHashMap : public HashMap<K,V>
{
    public:
        LinkedHashMap();
        LinkedHashMap(int size);    
        
        V get (K key);
        void put (K key, V value);
        void remove(K key);

        void clear();
        bool isEmpty();
        int size();

        int hash(K key);

        K search(V value);

        Iterator<V> iterator();
    
        ~LinkedHashMap();
    protected:
        Data<V> *list_begin;
        int list_size;
};


//LinkedIterator

template <typename T>
LinkedIterator<T>::LinkedIterator(Data<T> *first){
    this->begin = first;
    start();
}


template <typename T>
void Iterator<T>::start(){
    this->curr = this->begin;
}

template <typename T>
void Iterator<T>::next(){
    this->curr = this->curr->next;
}


template <typename T>
LinkedIterator<T>::~LinkedIterator(){

}


//LinkedIterator



//LinkedHashMap

template <typename K, typename V>
LinkedHashMap<K,V>::LinkedHashMap(){
    list_size = 0;
    list_begin = 0x0;
    this->data = new Data<V>[100];
    this->data_size = 100;
}

template <typename K, typename V>
LinkedHashMap<K,V>::LinkedHashMap(int size){
    list_size = 0;
    list_begin = 0x0;
    this->data = new Data<V>[size];
    this->data_size = size;
}

template <typename K, typename V>
LinkedHashMap<K,V>::~LinkedHashMap(){
    delete list_begin;
    delete this->data;
}


template <typename K, typename V>
int HashMap<K,V>::size(){
    return this->data_size;
}

template <typename K, typename V>
Iterator<V> LinkedHashMap<K,V>::iterator(){
    LinkedIterator<V> lIterator(list_begin);
    return lIterator;
}  

//LinkedHashMap


#endif // LINKEDHASHMAP_H