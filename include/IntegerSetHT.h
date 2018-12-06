#ifndef INTEGERSET_H
#define INTEGERSET_H

// #include "List.h"
#include <iostream>

using namespace std;
// IntegerSet abstract base class to demonstrate hash table concepts
namespace ece309
{
class IntegerSet {
    protected:
        int size;
        int hash(int key) const 
        {            
            return ((key*47)&~size) % size;
        }
    public:
        IntegerSet(int htsize):size(htsize) {}
        virtual bool insert(int) = 0;
        virtual bool search(int) const = 0;
        virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
    protected:
        int *table;
        int probeDistance;
        const int empty_since_start = -2;
        const int empty_after_removal = -1;
        int collisions;
        int failures;
    public:
        class HTIterator
        {
            private:
                int* ht;
                int key;
                int size;
                
            public:
                HTIterator(int* hashTable, int sz) : ht(hashTable), key(0), size(sz) {}
                void increment() { ++key; }
                int getValue() 
                {
                    if (ht[key] < 0)
                    {
                        ++key;
                        getValue();
                    }
                    return ht[key];
                }
                bool end() { return key > size; }

            friend class IntegerSetHT;

        };
        IntegerSetHT(int htsize=1000);
        virtual bool insert(int) override;
        virtual bool search(int) const override;
        virtual void remove(int) override;
        HTIterator begin()
        {
            return HTIterator(table, size);
        }
        void print();
};
}
#endif //INTEGERSET_H