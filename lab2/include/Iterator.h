#ifndef ITERATOR_H
#define ITERATOR_H

#include "Queue.h"

class Iterator
{
    public:
        Iterator(Queue &queue);
        void start();
        void next();
        bool finish();
        int getValue();
        virtual ~Iterator();
    protected:
    private:
        int index;
        int value;
        Queue q;
};

#endif // ITERATOR_H
