#include <stdio.h>

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
        bool remove_front(Item &copy);
        bool empty() {return head==NULL;}
};

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
}
LinkedList::~LinkedList()
{
    Item t;
    while(!empty())
    {
        remove_front(t);
    }
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

bool LinkedList::remove_front(Item &copy)
{
    if(!empty())
    {
        copy = head->getItem();
        Node *tmp = head->getNext();
        delete head;
        head = tmp;
        if (tmp==NULL)
            tail = NULL;
        return true;
    }
    return false;
}