#ifndef LIST_H
#define LIST_H

#include "iterator.h"

template <typename T>
class List
{
    struct Data{
        T value;
        struct Data* next;
	struct Data* prev;
    };
    public:
        List();
	virtual insert( Iterator pos, const T& value );
        virtual void erase( Iterator pos );
	virtual Iterator search(const T& value);
	void clear();
	bool empty();
	int size();
	virtual Iterator iterator();
	virtual ~List();
    protected:
    private:
        Data* tail;
        Data* head;
        int length;
};

#endif // LIST_H
