#ifndef PList_H
#define PList_H


#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;


class Container{
public:
  virtual void print(){ cout << "Container"<< endl;}
};


class String: public Container{
public:
  const char* str;
  String( const char *s = ""): str(s) {}
  void print() { cout << str << endl;}
};

//Object Hold a integer
class Integer : public Container{
public:
  int a;
  Integer(int b = 0): a(b) {}
  void print() {cout << a << endl;}
};

//Object Hold a duoble
class Double : public Container{
public:
  double x;
  Double(double y = 0): x(y){}
  void print(){cout<< x << endl;};
};

class PList{
private:

  class PListNode{
  private:
    Container *Obj;
  public:
    PListNode* next;
    PListNode(Container *o):Obj(o){next = NULL;}
    Container* getObject(){return Obj;}
    PListNode* getNext(){return next;}
  };
  PListNode *head;
  PListNode *tail;
public:

  class iterator{
  private:
    PListNode *node;
  public:
    iterator(PListNode *n=NULL) { node = n; }
    Container &getObject() { return *node->getObject(); }
    void increment() { node = node->next; }
    bool end() {  return node=NULL; }

    friend class PList;
  };
public:
  PList();
  void append(Container *a);
  void erase(iterator it);
  bool empty();
  void print();

  iterator begin(){
   return iterator(head);
 }
};

#endif
