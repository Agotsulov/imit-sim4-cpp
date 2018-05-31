#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
struct Data{
    T value;        
    struct Data* next;    
};

template <typename T>
class Iterator
{
    public:
        virtual void start();
        virtual T get();
        virtual void next(); 
        virtual bool isEmpty();
        virtual Data<T>* data();

        //virtual T operator++();
    protected:
        Data<T>* curr;
        Data<T>* begin;
    private:
};



#endif // ITERATOR_H
