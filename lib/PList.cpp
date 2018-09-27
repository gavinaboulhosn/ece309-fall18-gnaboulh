#include "PList.h"
#include <stdio.h>
#include <iostream>

using namespace std;

PList::PList(){
  head = NULL;
  tail = NULL;
}

void PList::append(Container *a){
  Node *node = new Node(a);
  if(head == NULL){
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

void PList::erase(PList::iterator it)
{

}

void PList::print()
{
  Node * current;
  current = head;
  while(current!=NULL)
  {
    current->getObject()->print();
    current = current->getNext();
  }

};


int main(){
  PList p;
  Container o;
  Container *o1 = new String("This is a test");
  Container *o2 = new Integer(15);
  Container *o3 = new Double(3.14);
  Container *o4 = new String("This test is complete.");
  p.append(o1);
  p.append(o2);
  p.append(o3);
  p.append(o4);
  p.print();
  cout <<endl;
}
