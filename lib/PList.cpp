#include "PList.h"
#include <stdio.h>
#include <iostream>

using namespace std;

PList::PList(){
  head = NULL;
  tail = NULL;
}

void PList::erase(PList::iterator& it)
{
    if(it.node==NULL)
    {
        Node *remove = head;
        head = head->getNext();
        if (head==NULL) tail = NULL;
        delete remove;
    }
    else
    {
        Node *tmp = it.node;
        Node *remove = tmp->getNext();
        tmp->next = remove->next; 
        if (tail == remove) tail = tmp;
        delete remove;
    }


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


void PList::print()
{
  Node * current;
  current = head;
  while(current!=NULL)
  {
    current->getObject()->print();
    current = current->getNext();
  }

}


int main()
{
  PList list;
  
  PList::iterator it = list.begin();
  
  
  Container *a = new String("Hello there");
  Container *b = new Integer(1520303);
  Container *c = new Double(234.23443343);
  Container *d = new String("I am now done with this homework");
  
  
  list.append(a);
  list.append(b);
  list.append(c);
  list.append(d);
  list.print();
  list.erase(it);
  list.erase(it);
  list.print();
}
