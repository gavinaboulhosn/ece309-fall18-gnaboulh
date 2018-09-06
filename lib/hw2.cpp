#include <stdio.h>
#include <iostream>

using namespace std;

class Item
{
    public:
        const char * str;
        Item(const char *s="")
        {
            str = s;
        }
};

class Node 
{
    private:
        Item item;
        Node *next;
    public:
        Node(Item a)
        {
            item = a;
            next = NULL;
        }
        void setNext(Node *n) {next = n;}
        Node* getNext() {return next;}
        Item getItem() {return item;}
        
};


class LinkedList
{
    private:
        
        Node *head;
        Node *tail;
    public:
        LinkedList();
        ~LinkedList();
        void push_back(Item a);
        Item get(int n);
        int length();
        Item remove_front();
        bool empty() {return head==NULL;}
        void print();
};

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    cout << "constructed" << endl;
}
LinkedList::~LinkedList()
{
    Item t;
    while(!empty())
    {
        remove_front();
        cout << "Destroyed" << endl;
    }
}

void LinkedList::print()
{
    Node *current;
    current = head;
    while(current!=NULL)
    {
        cout << current->getItem().str << "->";
        current = current->getNext();
    }
    cout << "NULL" << endl;
}
    
void LinkedList::push_back(Item a)
{
    Node *node = new Node(a);
    if (head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->setNext(node);
        tail = node;
    }
}

Item LinkedList::get(int n)
{
    Node* current = head;
    int count = 0;
    while(current != NULL)
    {
        if(count == n)
            return current->getItem();
        ++count;
        current = current->getNext();
    }
    return NULL;
}

int LinkedList::length()
{
    int count = 0;
    Node* p = head;
    while (p!=NULL)
    {
        ++count;
        p = p->getNext();
    }
    return count;
}

Item LinkedList::remove_front()
{
    if(!empty())
    {
        Item copy = head->getItem();
        Node *tmp = head->getNext();
        delete head;
        head = tmp;
        if (tmp==NULL)
            tail = NULL;
        return copy;
    }
    return NULL;
}
int main()
{
    Item a = Item("penis");
    Item b = Item("balls");
    Item c = Item("tits");
    Item d = Item("fuckyou");
    Item e = Item("fuckballsmcgee");
    LinkedList test = LinkedList();
    test.push_back(a);
    test.push_back(b);
    cout << test.get(1).str << endl << endl << endl;
    test.push_back(c);
    test.push_back(d);
    test.push_back(e);
    test.print();
    cout << endl;
    //test.remove_front();
    //test.remove_front();
    //test.print();

    return 0;
}