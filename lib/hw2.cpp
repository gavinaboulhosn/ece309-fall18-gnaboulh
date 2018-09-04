#include <stdio.h>

class Item
{
    public:
        const char * str;
        Item(const char *as="")
        {
            str = as;
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
        


};

class LinkedList
{
    private:
        
    public:
        Node *get(Node *n)
        {

        }
};