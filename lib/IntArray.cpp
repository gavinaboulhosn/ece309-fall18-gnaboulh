#include "IntArray.h"

IntArray IntArray::operator + (const IntArray &rhs) const
{
  IntArray result(length); // make object to hold return value,
  	                       // make long enough to hold this object’s data
    int i=0;
    for(i=0; i<length && i<rhs.length; i++)
       result.array[i] = array[i] + rhs.array[i];
    for(;i<length;i++) // if rhs.length is shorter, copy rest of array
       result.array[i] = array[i];
    return result;
}


int main()
{
  
  return 0;
}