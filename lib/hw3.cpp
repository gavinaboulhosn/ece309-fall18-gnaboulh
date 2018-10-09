#include <stdio.h>
#include <iostream>
#include <string.h>

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


class ListArray 
{
    private:
        int items;
        size_t size;
        Item* array;
    public:
        ListArray();
        ListArray(int initSize);
        ~ListArray();
        void push_back(Item str);
        Item& get(int n);
        int length();
        void remove_front();
        void print();

};

void ListArray::push_back(Item str)
{
    if(size < items+1)
    {
        size_t newSize = size*2;
        Item* newArr = new Item[newSize];
        memcpy(newArr, array, size*sizeof(Item));
        size = newSize;
        delete[] array;
        array = newArr;
    }
    array[items] = str;
    items += 1;
}

Item& ListArray::get(int n)
{
    return array[n];
}

int ListArray::length()
{
    return items;
}

void ListArray::remove_front()
{
    
    for(int i = 0; i < items-1; i++)
    {
        array[i]=array[i+1];

    }
    array[items-1] = "";
    items -=1;
    
    
}

ListArray::ListArray()
{
    ListArray(5);
}

ListArray::ListArray(int initSize)
{
    size = initSize;
    array = new Item[size];
    items = 0;
}


ListArray::~ListArray()
{
    cout << "deleted" << endl;
    delete[] array;
}

void ListArray::print()
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i].str << endl;
    }
}


int main(int argc, char const *argv[])
{
    ListArray test = ListArray(1);
    Item a = Item("a");
    Item b = Item("b");
    Item c = Item("c");
    Item d = Item("d");
    Item e = Item("e");
    test.push_back(a);
    test.push_back(b);
    test.push_back(c);
    test.push_back(d);
    test.push_back(e);
    cout << endl << test.length() << endl << endl;
    test.print();
    test.remove_front();
    cout << endl << test.length()<< endl << endl;
    test.print();
    cout << test.get(3).str << endl;
    return 0;
}
