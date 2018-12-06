#ifndef INTARRAY_H
#define INTARRAY_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>

namespace ece309{
class IntArray
{
    private:
        int* array;
        int length;
    public:
        IntArray(int l, int val = 0):length(l){
            array = new int[length];
            for(int i=0; i<length; i++){
            array[i] = val;
            }
        }
        ~IntArray()
        {
            delete[] array;
        }
        void set(int index, int val) 
        {
            array[index] = val;
        }

        int get(int index) {
            return array[index];
        }

        int getLength() { return length; }

        IntArray(const char* str);
        int& operator[](int index);
        IntArray& operator+=(const IntArray &rhs);
        IntArray operator+(const IntArray &rhs) const;
        IntArray operator-(const IntArray &rhs) const;
        IntArray operator*(int x) const;
        IntArray operator/(int x) const;
        IntArray operator<<(int count) const;
        operator char*() const;
        operator int() const;
        void print();
};
}
#endif
