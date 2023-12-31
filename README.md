# CS2_Lab8

## Introduction
Heaps in the STL are simply implemented as vectors of the object you wish to keep in a heap.  In class, we implemented the algorithms necessary to treat a vector of objects as a heap.  But these operations are included directly in C++ as functions from the STL.  I would like you to reimplement my code for testing our heaps, but just using the C++ functions for maintaining a heap.  I briefly described them in class, they are:

make_heap
push_heap
pop_heap
is_heap
You can find a general discussion of them from GeeksforGeeksLinks to an external site..  You can find a reference to them starting at this page from cplusplus.comLinks to an external site..  You may have to do a little further reading because the objects to be inserted into the heap are structures where you are comparing based on just one of the fields.

## The Code
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

class HeapData {
public:
    int priority;
    int theData;
    
    //setters
    void setPriority(int newPri){
        priority = newPri;
    }
    void setData(int newData){
        theData = newData;
    }    

    //getters
    int getPriority(){
        return priority;
    }
    int getData(){
        return theData;
    }

};

int RandInRange(int low, int high) {
    return (low + rand()%(high - low + 1));
}

int main() {
    srand(time(0));
    int pdata[] = {30, 50, 70, 20, 80, 90, 200, 15, 25, 30};
    HeapData hpdata[10];
    for (int i = 0; i < 10; i++) {
        hpdata[i].setPriority(pdata[i]);
        hpdata[i].setData(i);
    }
    // TODO create initial heap named myHeap with data
    // from hpdata, and a second heap named myHeap2 with
    // the same data but where it is a min heap

    // TODO show the heap data in myHeap and myHeap2

    const int TESTSIZE = 1000;
    HeapData sdata[TESTSIZE];
    HeapData hdata1[TESTSIZE];
    HeapData hdata2[TESTSIZE];
    // TODO: Create an empty heap named heap1

    for (int i = 0; i < TESTSIZE; i++) {
        sdata[i].setPriority(RandInRange(0,TESTSIZE * 10));
        sdata[i].setData(i);
        // TODO: Insert data item sdata[i] into the heap

    }
    // TODO: check that heap1 is a heap

    // TODO: create a heap named heap2 from the data in
    //   sdata (read into a vector then make that a
    //   heap)

    for (int i = (TESTSIZE - 1); i >= 0; i--) {
        // hdata1[i] = 
        // TODO:  set hdata1[i] to insert top of heap1,
        //  then pop heap1

        // TODO: set hdata1[i] to insert top of heap2,
        // then pop heap2

    }
    sort(sdata,sdata + TESTSIZE);
    for (int i = 0; i < TESTSIZE; i++) {
        if (sdata[i].getPriority() != hdata1[i].getPriority()) {
            cout << "Heap 1 value at " << i << " = " << hdata1[i].getPriority() << " does not match " << sdata[i].getPriority() << "\n";
        }
        if (sdata[i].getPriority() != hdata2[i].getPriority()) {
            cout << "Heap 2 value at " << i << " = " << hdata2[i].getPriority() << " does not match " << sdata[i].getPriority() << "\n";
        }
    }
    return 0;
}
## What to Submit
Submit your solution as a CPP file. Give the file the name AssignmentTypeNumberLastNameFirstName.cpp (so, for example, my submission for Lab 3 would be named Lab3MaclinRichard.cpp). You should also include your first and last name in the file as a comment. Add a long comment in your code showing examples of the results produced from your code.