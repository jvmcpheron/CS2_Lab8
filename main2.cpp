//Jane McPheron

/*

Max Heap: 200 80 90 25 50 30 70 15 20 30 
Min Heap: 15 20 70 25 30 90 200 50 30 80 


*/



#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <ctime>
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

    vector<HeapData> myHeap(hpdata, hpdata + 10);
    vector<HeapData> myHeap2(hpdata, hpdata + 10);

    make_heap(myHeap.begin(), myHeap.end(), [](HeapData& a, HeapData& b) {
        return a.getPriority() < b.getPriority();
    });

    make_heap(myHeap2.begin(), myHeap2.end(), [](HeapData& a, HeapData& b) {
        return a.getPriority() > b.getPriority();
    });

    // TODO show the heap data in myHeap and myHeap2
    cout << "Max Heap: ";
    for (auto& item : myHeap) {
        cout << item.getPriority() << " ";
    }
    cout << endl;

    cout << "Min Heap: ";
    for (auto& item : myHeap2) {
        cout << item.getPriority() << " ";
    }


    const int TESTSIZE = 1000;
    HeapData sdata[TESTSIZE];
    HeapData hdata1[TESTSIZE];
    HeapData hdata2[TESTSIZE];
    // TODO: Create an empty heap named heap1
    vector<HeapData> heap1;

    for (int i = 0; i < TESTSIZE; i++) {
        sdata[i].setPriority(RandInRange(0, TESTSIZE * 10));
        sdata[i].setData(i);
        // TODO: Insert data item sdata[i] into the heap

        heap1.push_back(sdata[i]);
        push_heap(heap1.begin(), heap1.end(), [](HeapData& a, HeapData& b) {
            return a.getPriority() < b.getPriority();
        });
    }

    // TODO: check that heap1 is a heap
    bool isHeap1 = is_heap(heap1.begin(), heap1.end(), [](HeapData& a, HeapData& b) {
        return a.getPriority() < b.getPriority();
    });

    cout << "Is this a heap? " << isHeap1 << endl;

    // TODO: create a heap named heap2 from the data in
    //   sdata (read into a vector then make that a
    //   heap)
    vector<HeapData> heap2(sdata, sdata + TESTSIZE);
    make_heap(heap2.begin(), heap2.end(), [](HeapData& a, HeapData& b) {
        return a.getPriority() < b.getPriority();
    });

    for (int i = (TESTSIZE - 1); i >= 0; i--) {
        hdata1[i] = heap1.front();
        // TODO:  set hdata1[i] to insert top of heap1,
        //  then pop heap1

        pop_heap(heap1.begin(), heap1.end(), [](HeapData& a, HeapData& b) {
            return a.getPriority() < b.getPriority();
        });
        heap1.pop_back();

        // TODO: set hdata1[i] to insert top of heap2,
        // then pop heap2

        hdata2[i] = heap2.front();
        pop_heap(heap2.begin(), heap2.end(), [](HeapData& a, HeapData& b) {
            return a.getPriority() < b.getPriority();
        });
        heap2.pop_back();

    }

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