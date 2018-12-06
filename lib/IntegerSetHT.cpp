#include "IntegerSetHT.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace ece309;
// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
   collisions = 0;
   failures = 0;
   probeDistance = 10;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
    
}

bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     return true;
   }
   if(bucketsProbed==2)
      collisions+=1;
   index = (index+1) % size;
  }
  // otherwise give up
   failures+=1;
   return false;
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}

void IntegerSetHT::print()
{
    cout << "Collisions: " << collisions << endl;
    cout << "Insertion failures: " << failures << endl;
}
