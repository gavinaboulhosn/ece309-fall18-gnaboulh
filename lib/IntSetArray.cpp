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
  IntegerSetArray(int lef, int val);
  bool insert(int x);
  bool search(int x) const;
  void remove(int x);
  void print();
};

IntegerSetArray::IntegerSetArray(int le, int val = 0)
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

int main()
{
    int testPassCnt = 0;
    int testFailCnt = 0;

    printf("constructing an integer set of size 3 ...\n");
    IntegerSetArray isa(3);

    for (int i=0;i<4;i++)
    {
        bool insertResult = isa.insert(i);
        if(insertResult)
        {
            if (i<3)
                testPassCnt++;
            else
                testFailCnt++;
        }
        else {
            if (i<3)
                testFailCnt++;
            else
                testPassCnt++;
        }
        // for 1,2,3 should return true, for 4 should return false
        printf("Insert result of %d: %d\n",i,insertResult);
    }

    // test the search function
    if (isa.search(2)){
        testPassCnt++;
    }
    else {
        testFailCnt++;
        printf("search 2 test failed ... \n");
    }
    if (isa.search(4)){
        testFailCnt++;
        printf("search 4 test failed ... \n");
    }
    else {
        testPassCnt++;
    }

    // test the remove function
    isa.remove(2);
    // after remove 2, search of 2 should return false
    if(isa.search(2))
    {
        testFailCnt++;
        printf("remove 2 test failed ... \n");
    }
    else
        testPassCnt++;

    // print test result
    printf("Tests passed: %d, tests failed: %d\n",testPassCnt,testFailCnt);

    if (testFailCnt)
        return 1;
    else
        return 0;
}
