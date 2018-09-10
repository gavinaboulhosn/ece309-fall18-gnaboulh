#include <stdio.h>
#include <iostream>

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

class Item
{
    public:
        const char * str;
        Item(const char *s="")
        {
            str = s;
        }
};






int main(int argc, char const *argv[])
{
    
    return 0;
}
