#ifndef LIST_H
#define LIST_H


template <typename T>
class List
{
    struct Data{
        T value;
        struct Data* next;
    };
    public:
        List();
        void push(const T value);
        int size();
        T pop(int index);
        virtual ~List();
    protected:
    private:
        Data* tail;
        Data* head;
        int length;
};



template <typename T>
List<T>::List()
{
    this->length = 0;
}

template <typename T>
int List<T>::size(){
    return this->length;
}

template <typename T>
void List<T>::push(const T value){
    length++;
    Data* d = new Data;
    d->value = value;
    d->next = this->head;
    this->head = d;
}


template <typename T>
T List<T>::pop(int index){
    Data *d = this->head;
    for(int i = 0;i < size() - 1 - index;i++){
        d = d->next;
    }
    return d->value;
}

template <typename T>
List<T>::~List()
{
    //dtor
}




#endif // LIST_H
