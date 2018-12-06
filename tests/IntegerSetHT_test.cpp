#include "IntegerSetHT.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace ece309;

int main()
{
    IntegerSetHT ht(1000);
    srand(time(NULL));
    for(int i = 0; i < 500; i++)
    {
        ht.insert(rand()%1000);
    }
    ht.print();

    IntegerSetHT set;
    //set.insert(5);
    //set.insert(99);
    //set.insert(0);

    IntegerSetHT::HTIterator it = set.begin();


    

    int i = 0;
    while(!it.end())
    {
        cout << "I: " << i++ << endl;
        cout << it.getValue() << endl;
        it.increment();
    }
    // set.print();
    return 0;
}