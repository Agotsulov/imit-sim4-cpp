#ifndef ITERATOR_H
#define ITERATOR_H

template <typename V, typename K>
struct Data{
    V value;        
    K key;
    struct Data* next;    
};

template <typename V, typename K>
class Iterator
{
    public:
        virtual void start();
        virtual V get();
        virtual void next(); 
        virtual bool isEmpty();
        virtual Data<V,K>* data();

        //virtual T operator++();
    protected:
        Data<V,K>* curr;
        Data<V,K>* begin;
    private:
};



#endif // ITERATOR_H
