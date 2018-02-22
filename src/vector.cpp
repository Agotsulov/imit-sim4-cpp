#include "../include/Vector.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

Vector::vector()
{
    len = 0;
    array = new int[0];
}

Vector::vector(int n)
{
    len = n;
    array = new int[len];
    for(int i = 0;i < len;i++){
        array[i] = 0;
    }
}

Vector::vector(int n,int value)
{
    len = n;
    array = new int[len];
    for(int i = 0;i < len;i++){
        array[i] = value;
    }
}

Vector::vector(int n,int value,int size_reserve)
{
    len = n;
    array = new int[len];
    for(int i = 0;i < len;i++){
        array[i] = value;
    }
    reserve(size_reserve);
}


Vector::vector(const Vector *other)
{
    //std::cout << "Копирование начало" << std::endl;
    len = (*other).len;
    array = new int[len];

    memcpy(array, (*other).array, (*other).len * sizeof(int));

    //std::cout << "Копирование конец" << std::endl;
}

Vector::vector(Vector& other)
{
    //std::cout << "Перемещение начало" << std::endl;
    len = other.len;
    array = new int[len];

    memcpy(array, other.array, other.len * sizeof(int));

    other.~Vector();
    //std::cout << "Перемещение конец" << std::endl;
}

int Vector::length(){
    return len;
}

void Vector::resize(int new_size){
    if(new_size > length() + capacity()){
        int *newArray = new int[new_size];
        if(new_size > length()){
            for(int i = 0;i < length();i++){
                newArray[i] = array[i];
            }
            for(int i = length();i < (new_size - length());i++){
                newArray[i] = 0;
            }
        }
        else
            for(int i = 0;i < new_size;i++){
                newArray[i] = array[i];
            }
        array = newArray;
    }else{
        len = new_size;
    }
}


int Vector::operator[](const int idx){
    if( (idx < 0) || (idx > length()) ) return 0;
    return array[idx];
}

Vector& Vector::operator=(const Vector& other){
    Vector v(&other);
    return v;
}

bool Vector::operator==(const Vector& other){
    if(len != other.len) throw "Массивы разных длинн";
    for(int i = 0;i < len;i++)
        if(array[i] != other.array[i]) return false;
    return true;
}

bool Vector::operator!=(const Vector& other){
    if(length() != other.len) {
        throw "Массивы разных длинн";
        return false;
    }
    for(int i = 0;i < len;i++)
        if(array[i] == other.array[i]) return false;
    return true;
}

bool Vector::operator>(const Vector& other){
    if(len >= other.len)
        for(int i = 0;i < other.len;i++)
            if(array[i] < other.array[i]) return false;
    else
        for(int i = 0;i < len;i++)
            if(array[i] < other.array[i]) return false;
    return true;
}


bool Vector::operator<(const Vector& other){
    if(len <= other.len)
        for(int i = 0;i < other.len;i++)
            if(array[i] > other.array[i]) return false;
    else
        for(int i = 0;i < len;i++)
            if(array[i] > other.array[i]) return false;
    return true;
}


bool Vector::operator>=(const Vector& other){
    if(len >= other.len)
        for(int i = 0;i < other.len;i++)
            if(array[i] <= other.array[i]) return false;
    else
        for(int i = 0;i < len;i++)
            if(array[i] <= other.array[i]) return false;
    return true;
}


bool Vector::operator<=(const Vector& other){
    if(len <= other.len)
        for(int i = 0;i < other.len;i++)
            if(array[i] >= other.array[i]) return false;
    else
        for(int i = 0;i < len;i++)
            if(array[i] >= other.array[i]) return false;
    return true;
}

Vector& Vector::operator+(const Vector &other){
    Vector result(len + other.len);
    for(int i = 0;i < len;i++)
        result.array[i] = array[i];
    for(int i = 0;i < other.len;i++)
        result.array[len + i] = array[i];
    return result;
}

void Vector::reserve(int size){
    reserved = size;
    array = (int*)realloc(array, sizeof(int) * size);
    int * new_array = new int[len + reserved];
    memcpy(new_array,array,len * sizeof(int));
}
int Vector::capacity(){
    return reserved;
}

void Vector::pushBack(int value){
    resize(length() + 1);
    array[length() - 1] = value;
}


int Vector::popBack(){
    resize(length() - 1);
    return array[length()];
}

std::ostream& Vector::operator<<(std::ostream& out)
{
    for(int i = 0;i < length();i++)
        out << array[i] << ' ';
    return out;
}

std::istream& Vector::operator>>(std::istream& in)
{
    for(int i = 0;i < length();i++)
        in >> array[i];
    return in;
}


Vector::~Vector()
{
    reserved = 0;
    len = 0;
    delete array;
}
