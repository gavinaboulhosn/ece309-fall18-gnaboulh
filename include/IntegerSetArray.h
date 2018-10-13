#ifndef INTSETARRAY_H
#define INTSETARRAY_H

#include <stdio.h>
#include <iostream>

using namespace std;

class IntegerSet {
protected:
   int size;
   int hash(int key) { return (key * 997) % size;}
public:
   IntegerSet(int htsize):size(htsize){}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
   virtual void print() = 0;
};

class IntegerSetArray: public IntegerSet{
private:
  int size;
  int ints;
  int* array;
public:
  IntegerSetArray(int lef, int val=0);
  bool insert(int x);
  bool search(int x) const;
  void remove(int x);
  void print();
};



#endif