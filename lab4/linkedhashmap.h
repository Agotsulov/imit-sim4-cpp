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
class LinkedHashMap
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
        Data<V> *list_end;
        int list_size;

        Data<V> *data;
        int data_size;
};


//LinkedIterator

template <typename T>
LinkedIterator<T>::LinkedIterator(Data<T> *first){
    this->begin = first;
    this->start();
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
T Iterator<T>::get(){
    return this->curr->value;
}

template <typename T>
bool Iterator<T>::isEmpty(){
    if(this->curr == 0x0)
        return true;
    else 
        return false;
}

template <typename T>
Data<T>* Iterator<T>::data(){
    return this->curr;
}


template <typename T>
LinkedIterator<T>::~LinkedIterator(){

}


//LinkedIterator



//LinkedHashMap

template <typename K, typename V>
LinkedHashMap<K,V>::LinkedHashMap(){
    list_size = 0;
    list_begin = new Data<V>;
    list_end = list_begin;
    this->data = new Data<V>[100];
    this->data_size = 100;
}

template <typename K, typename V>
LinkedHashMap<K,V>::LinkedHashMap(int size){
    list_size = 0;
    list_begin = new Data<V>;
    list_end = list_begin;
    this->data = new Data<V>[size];
    this->data_size = size;
}

template <typename K, typename V>
LinkedHashMap<K,V>::~LinkedHashMap(){
    delete list_begin;
    delete this->data;
}

template <typename K, typename V>
bool LinkedHashMap<K,V>::isEmpty(){
    if(list_size == 0) 
        return true;
    else 
        return false;
}

template <typename K, typename V>
void LinkedHashMap<K,V>::clear(){
    delete this->data;
    delete list_begin;
    //Дописать удальние лист
    delete list_end;
}


template <typename K, typename V>
int LinkedHashMap<K,V>::size(){
    return this->data_size;
}

template <typename K, typename V>
int LinkedHashMap<K,V>::hash(K key){
    return key % data_size;
}

template <typename K, typename V>
V LinkedHashMap<K,V>::get(K key){
    return this->data[this->hash(key)].value;
}

template <typename K, typename V>
void LinkedHashMap<K,V>::put(K key, V value){
    //Дописать коллизии
    this->data[this->hash(key)].value = value;
    if(list_size != 0){
        Data<V> *curr = new Data<V>;
        curr->value = value;
        curr->next = 0x0;
        list_end->next = curr;
        list_end = curr;
    } else {
        Data<V> *curr = new Data<V>;
        curr->value = value;
        curr->next = 0x0;
        list_begin = curr;
    }
    list_size++;
}   

template <typename K, typename V>
void LinkedHashMap<K,V>::remove(K key){
    this->data[this->hash(key)].value = 0;
    this->data[this->hash(key)].next = 0x0;
    //Дописать перенос коллизий
}




template <typename K, typename V>
Iterator<V> LinkedHashMap<K,V>::iterator(){
    LinkedIterator<V> lIterator(list_begin);
    return lIterator;
}  

//LinkedHashMap


#endif // LINKEDHASHMAP_H