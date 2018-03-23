#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Iterator
{
    public:
        Iterator();
	virtual void start();
	virtual T get();
	virtual void next();
	virtual bool empty();
	virtual ~Iterator();
    protected:
    private:
};

#endif // ITERATOR_H
