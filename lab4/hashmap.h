#ifndef HASHMAP_H
#define HASHMAP_H

#include "iterator.h"

template <typename K, typename V>
class HashMap{
    public:
        virtual V get (K key);
        virtual void put (K key, V value);
        virtual void remove(K key);

        virtual void clear();
        virtual bool isEmpty();
        virtual int size();

        virtual int hash(K key);

        virtual K search(V value);

        virtual Iterator<V> iterator();
    protected:
        Data<V> *data;
        int data_size;
};

#endif // HASHMAP_H