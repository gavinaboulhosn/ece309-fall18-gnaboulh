#include "IntArray.h"

using namespace std;

IntArray::IntArray(const char* str)
{
  length = strlen(str);
  array = new int[length];
  for(int i = 0; i <= length; i++ )
  {
    array[i] = str[i];
  }
}
int&  IntArray::operator[](int index)
{
  return array[index];
}
IntArray& IntArray::operator+=(const IntArray &rhs)
{
  for(int i = 0; i<length; i++){
    int rval= rhs.array[i];
    array[i] = array[i] + rval;
  }
  return *this;
}
IntArray IntArray::operator+(const IntArray &rhs) const{
  IntArray result(length); // make object to hold return value,
  	                       // make long enough to hold this object’s data
    int i = 0;
    for(i=0; i<length && i<rhs.length; i++)
       result.array[i] = array[i] + rhs.array[i];
    for(;i<length;i++) // if rhs.length is shorter, copy rest of array
       result.array[i] = array[i];
return result;
}
IntArray IntArray::operator-(const IntArray &rhs) const{
  IntArray result(length);

  int j = 0;
  for(j=0; j < length && j<rhs.length; j++)
    result.array[j] = array[j] - rhs.array[j];
  for(; j<length; j++)
    result.array[j] = array[j];
 return result;
}
IntArray IntArray::operator*(int x) const{
  IntArray result(length);

  for(int i = 0; i <=length; i++)
    result.array[i] = x*array[i];
  return result;
}
IntArray IntArray::operator/(int x) const{
  IntArray result(length);

  for(int i = 0; i <=length; i++)
    result.array[i] = array[i]/x;
  return result;
}
IntArray IntArray::operator<<(int count) const{
  IntArray result(length);
  int i =0;
  count = count % length;
  while(i<length){
    result.array[count] = array[i];
    i++;
    count++;
    if(count>=length)
      count-=length;
  }

  return result;
}
IntArray::operator char*() const{
  string str = "";
  bool flag = false;
  for (int i =0; i<length; i++)
  {
    if(array[i] < 0 || array[i] >255)
    {
      if(array[i] == 0) flag = true;
      str += " ";
    }
    else
    {
        str+= (char)array[i];
    }
      
  }
  if(!flag)
  {
    str+=(char)0;
  }
  char * ret = new char[str.length() + 1];
  strcpy(ret, str.c_str());
  return ret;
}

IntArray::operator int() const{
  int total = 0;
  for(int i = 0; i<=length; i++){
    total += array[i];
  }
  return total/length;
}

void IntArray::print(){
    for (int i =0; i<length; i++) {
        cout << array[i] << endl;
    }
}

