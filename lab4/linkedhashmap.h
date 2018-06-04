#ifndef LINKEDHASHMAP_H
#pragma once

#include "hashmap.h"

template <typename V, typename K>
class LinkedIterator : public Iterator<V,K>
{
    public:
        LinkedIterator(Data<V,K> *first);
        ~LinkedIterator();
};

template <typename K, typename V>
class LinkedHashMap //: public HashMap<K,V>{
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

        Iterator<V,K> iterator();  
        
        ~LinkedHashMap();
    protected:
        Data<V,K> *list_begin;
        Data<V,K> *list_end;
        int list_size;

        Data<V,K> **data;
        int data_size;
};

/*
    В классах для ключей должны быть переопределен оператор int()
    operator int() const 
*/


//LinkedIterator

template <typename V, typename K>
LinkedIterator<V,K>::LinkedIterator(Data<V,K> *first){
    this->begin = first;
    this->start();
}


template <typename V, typename K>
void Iterator<V,K>::start(){
    this->curr = this->begin;
}

template <typename V, typename K>
void Iterator<V,K>::next(){
    this->curr = this->curr->next;
}

template <typename V, typename K>
V Iterator<V,K>::get(){
    return this->curr->value;
}

template <typename V, typename K>
bool Iterator<V,K>::isEmpty(){
    if(this->curr == 0x0)
        return true;
    else 
        return false;
}

template <typename V, typename K>
Data<V,K>* Iterator<V,K>::data(){
    return this->curr;
}


template <typename V, typename K>
LinkedIterator<V,K>::~LinkedIterator(){

}


//LinkedIterator



//LinkedHashMap

template <typename K, typename V>
LinkedHashMap<K,V>::LinkedHashMap(){
    list_size = 0;
    list_begin = new Data<V,K>;
    list_end = list_begin;
    this->data = new Data<V,K>*[100];
    this->data_size = 100;
}

template <typename K, typename V>
LinkedHashMap<K,V>::LinkedHashMap(int size){
    list_size = 0;
    list_begin = new Data<V,K>;
    list_end = list_begin;
    this->data = new Data<V,K>*[size];
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
    for(int i = 0; i < data_size; i++){
        delete this->data[i];
    }
    delete this->data;

    Data<V,K> *curr = list_begin;
    while(curr != list_end){
        curr = curr->next;
        delete curr;
    }

    //delete list_begin;
    //delete list_end;
}

template <typename K, typename V>
int LinkedHashMap<K,V>::size(){
    return this->data_size;
}

template <typename K, typename V>
int LinkedHashMap<K,V>::hash(K key){
    return key % this->data_size;
}


template <typename K, typename V>
V LinkedHashMap<K,V>::get(K key){
    if(list_size == 0)
        throw "Таблица пуста";

    V result;

    int hash_result = hash(key);

    if(data[hash_result]->next != 0x0){
        Data<V,K> *curr = data[hash_result];
        while(curr->key != key)
            curr = curr->next;
        result = curr->value;
    } else {
        if(data[hash_result]->key == key)
            result = data[hash_result]->value;
        else 
            throw "Элемент не найден";
    }
    return result;
}


template <typename K, typename V>
K LinkedHashMap<K,V>::search(V value){    
    Data<V,K> *curr = list_begin;
    while(curr != 0x0){
        if(curr->value == value){
            return curr->key;
        }
        curr = curr->next;
    }    

    throw "Элемент не найден";
}


template <typename K, typename V>
void LinkedHashMap<K,V>::put(K key, V value){

    int hash_result = hash(key);
    if(data[hash_result] == 0x0){
        data[hash_result] = new Data<V,K>;
        data[hash_result]->key = key;
        data[hash_result]->value = value;
        data[hash_result]->next = 0x0;
    } else {
        Data<V,K> *last = data[hash_result];
        while(last->next != 0x0)
            last = last->next;
        
        Data<V,K> *new_data = new Data<V,K>;
        new_data->key = key;
        new_data->value = value;
        new_data->next = 0x0;
        data[hash_result]->next = new_data;
    }
    
    if(list_size != 0){
        Data<V,K> *curr = new Data<V,K>;
        curr->value = value;
        curr->next = 0x0;
        curr->key = key;
        list_end->next = curr;
        list_end = curr;
    } else {
        Data<V,K> *curr = new Data<V,K>;
        curr->value = value;
        curr->next = 0x0;
        curr->key = key;
        list_begin = curr;
        list_end = list_begin;
    }
    list_size++;
}   

template <typename K, typename V>
void LinkedHashMap<K,V>::remove(K key){
    //Пробежку по листу
    if(list_size == 0)
        throw "Таблица пуста";


    if(list_begin->key == key){
        Data<V,K> *buff = list_begin;
        list_begin = buff->next;
        delete buff;
    } else {
        Data<V,K> *curr = list_begin;
        while((curr->next != 0x0) && (curr->next->key != key))
            curr = curr->next;

        if(curr->next == 0x0)
            throw "Нет такого элемента";

        if(curr->next->next == 0x0){
            delete curr->next;
            curr->next = 0x0;
            list_end = curr;
        } else {
            Data<V,K> *buff = curr->next->next;
            delete curr->next;
            curr->next = buff;
        }
    }


    int hash_result = hash(key);

    if(data[hash_result]->next == 0x0){
        data[hash_result]->value = 0;
        data[hash_result]->key = 0;
        data[hash_result]->next = 0x0;
    } else {

        if(data[hash_result]->key == key){
            Data<V,K> *buff = data[hash_result];
            data[hash_result] = buff->next;
            delete buff;
        } else {
            Data<V,K> *curr_data = data[hash_result];
            while((curr_data->next != 0x0) && (curr_data->next->key != key))
                curr_data = curr_data->next;
            
            if(curr_data->next == 0x0)
                throw "Нет такого элемента";

            if(curr_data->next->next == 0x0){
                delete curr_data->next;
                curr_data->next = 0x0;
            } else {
                Data<V,K> *buff = curr_data->next->next;
                delete curr_data->next;
                curr_data->next = buff;
            }    
        }
    }
    //Дописать перенос коллизий
}



template <typename K, typename V>
Iterator<V,K> LinkedHashMap<K,V>::iterator(){
    LinkedIterator<V,K> lIterator(list_begin);
    return lIterator;
}  


//LinkedHashMap


#endif // LINKEDHASHMAP_H