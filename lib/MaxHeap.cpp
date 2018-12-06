#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class MaxHeap {
private:
  int *heapArray;    // this is the maxheap
  int heapArraySize; // size of the array
  int nextIndex;     // location of next free array entry

protected:
  void percolate_up(int);
  void percolate_down(int, int);

public:
  MaxHeap(int size = 100) : heapArraySize(size) {
    heapArray = new int[size];
    for (int i = 0; i < size; i++)
      heapArray[i] = 0;
    nextIndex = 0;
  }
  void topthree(int &gold, int &silver, int &bronze) const
  {
    switch(nextIndex)
    {
      case 0:
         gold = -1;
         silver = -1;
         bronze = -1;
         break;
      case 1:
         gold = heapArray[0];
         silver = -1;
         bronze = -1;
         break;
      case 2:
         gold = heapArray[0];
         silver = heapArray[1] > heapArray[2] ? heapArray[1] : heapArray[2];
         bronze = -1;
         break;
         
      default:
         gold = heapArray[0];
         silver = heapArray[1] > heapArray[2] ? heapArray[1] : heapArray[2];
         bronze = silver == heapArray[1] ?  heapArray[2] : heapArray[1];
         break;
    };
  }
  /*
    Return the top three values in max-heap with O(1) time complexity.  This function
    may not change contents or member variables.  If the heap has fewer than 3 elements, 
    only assign values to the references that have a corresponding value.  For example, 
    if the max-heap is a single value, only gold is set.  If it has two values, then gold 
    and silver are set.  For more than two elements, gold, silver, and bronze should all 
    be set accordingly.
  */
  void print() {
    for (int i = 0; i < nextIndex; i++) {
      printf("%d ", heapArray[i]);
    }
    printf("\n");
  }

  bool insert(int);
  bool remove(int &); // remove the max value

private:
  MaxHeap(int *array, int size, int length = 0)
      : heapArray(array), heapArraySize(size), nextIndex(length) {
    int m = nextIndex / 2 - 1; // last internal BTNode
    while (m >= 0) {
      percolate_down(m, length);
      m--;
    }
  }

public:
  static void sort(int *array, int size);
};

void MaxHeap::percolate_up(int index) {
  while (index > 0) {
    int parent_index = (index - 1) / 2;
    if (heapArray[index] > heapArray[parent_index]) {
      int tmp = heapArray[index];
      heapArray[index] = heapArray[parent_index];
      heapArray[parent_index] = tmp;
      index = parent_index;
    } else
      return;
  }
}

void MaxHeap::percolate_down(int index, int size) {
  int child_index = index * 2 + 1;
  int val = heapArray[index];
  while (child_index < size) {
    int max_val = val;
    int max_index = -1;
    for (int i = child_index; i < child_index + 2 && i < size; i++) {
      if (heapArray[i] > max_val) {
        max_val = heapArray[i];
        max_index = i;
      }
    }
    if (max_val == val)
      return;
    heapArray[index] = max_val;
    heapArray[max_index] = val;
    index = max_index;
    child_index = index * 2 + 1;
  }
}

bool MaxHeap::insert(int data) {
  if (nextIndex < heapArraySize) {
    heapArray[nextIndex] = data;
    percolate_up(nextIndex);
    nextIndex++;
    return true;
  } else {
    return false;
  }
}

bool MaxHeap::remove(int &val) {
  if (nextIndex > 0) {
    val = heapArray[0];
    heapArray[0] = heapArray[nextIndex - 1];
    nextIndex -= 1;
    percolate_down(0, nextIndex);
    return true;
  }
  return false;
}

void MaxHeap::sort(int *array, int size) {
  MaxHeap heap(array, size, size);

  printf("\nheapify: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }

  for (int i = size - 1; i > 0; i--) {
    int ref;
    heap.remove(ref);
    array[i] = ref;
  }

  // return, and the array passed in is sorted
}

int main()
{
    MaxHeap heap;
    int gold;
    int silver;
    int bronze;
    heap.insert(46);
    heap.insert(60);
    heap.insert(3300);
    heap.insert(45);
    heap.topthree(gold, silver, bronze);
    cout << "Gold " << gold << endl;
    cout << "Silver " << silver << endl;
    cout << "Bronze " << bronze << endl;
    

    return 0;
}
