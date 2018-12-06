#include "IntegerSetArray.h"
using namespace ece309;
IntegerSetArray::IntegerSetArray(int le, int val)
:IntegerSet(le)
{
    size = le;
    array = new int[size];
    for(int i=0; i<size; i++){array[i] = val;}
    ints = 0;
}

bool IntegerSetArray::insert(int x){
  if(size < ints + 1)
  {
    return false;
  } 
  else
  {
    array[ints] = x;
    ++ints;
  }
  return true;
}

bool IntegerSetArray::search(int x) const{
  for(int i = 0; i<= size; i++)
  {
    if(x == array[i])
    {
      return true;
    }
  }
return false;
}

void IntegerSetArray::remove(int x){
  for(int i = 0; i<= size; i++)
  {
    if(x == array[i])
    { 
        array[i] = 0;
    }
  }
}

void IntegerSetArray::print(){
  for(int z = 0; z < size; z++){
    cout << array[z] << endl;
  }
}

