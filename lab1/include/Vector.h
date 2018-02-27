#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
    public:
        Vector();
        Vector(int n);
        Vector(int n,int value);
        Vector(int n,int value,int size_reserve);
        Vector(Vector &other);
        Vector(Vector &&other);
        int length();
        void resize(int new_size);
        int operator[](const int idx);
        Vector& operator=(Vector &other);
        void operator=(Vector&& other);
        bool operator==(const Vector &other);
        bool operator!=(const Vector &other);
        bool operator<(const Vector &other);
        bool operator>(const Vector &other);
        bool operator<=(const Vector &other);
        bool operator>=(const Vector &other);
        Vector& operator+(const Vector &other);
        std::ostream& operator<<(std::ostream &out);
        std::istream& operator>>(std::istream &in);
        void reserve(int size);
        int capacity();
        void pushBack(int value);
        int popBack();
        virtual ~Vector();
    protected:
    private:
        int *array;
        int len;
        int reserved = 10;
};


#endif // VECTOR_H
