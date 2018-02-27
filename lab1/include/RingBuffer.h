#ifndef RINGBUFFER_H
#define RINGBUFFER_H
#include "Vector.h"

class RingBuffer : public Vector
{
    public:
        RingBuffer(int size);
        void push(int value);
        int pop(); //Удаляет
        int get();
        int length();
        bool empty();
        void makeEmpty();
        virtual ~RingBuffer();
    protected:
    private:
        int indexEnd;
        int indexBegin;
};

#endif // RINGBUFFER_H
