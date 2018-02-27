#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue();
        Queue(int size);
        void push(int value);
        int pop();
        int get();
        int size();
        void empty();
        bool isEmpty();
        virtual ~Queue();
    protected:
    private:
        int* array;
        int sizeArray;
        int head;
        int tail;
};

#endif // QUEUE_H
