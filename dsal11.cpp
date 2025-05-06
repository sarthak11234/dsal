#include <iostream>
using namespace std;

class Heap {
    int n;
    int* minheap;
    int* maxheap;

public:
    void get();
    void displayMin() { cout << "Minimum marks are: " << minheap[0] << endl; }
    void displayMax() { cout << "Maximum marks are: " << maxheap[0] << endl; }
    void upAdjustMin(int);
    void upAdjustMax(int);
    ~Heap();  // Destructor to clean up memory
};

void Heap::get() {
    cout << "Enter number of students: ";
    cin >> n;
    int k;
    minheap = new int[n];
    maxheap = new int[n];
    cout << "Enter marks of students:\n";

    for (int i = 0; i < n; i++) {
        cin >> k;
        minheap[i] = k;
        upAdjustMin(i);  // Maintain min-heap

        maxheap[i] = k;
        upAdjustMax(i);  // Maintain max-heap
    }
}

void Heap::upAdjustMin(int i) {
    int temp = minheap[i];
    while (i > 0 && temp < minheap[(i - 1) / 2]) {
        minheap[i] = minheap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minheap[i] = temp;
}

void Heap::upAdjustMax(int i) {
    int temp = maxheap[i];
    while (i > 0 && temp > maxheap[(i - 1) / 2]) {
        maxheap[i] = maxheap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    maxheap[i] = temp;
}

Heap::~Heap() {
    delete[] minheap;
    delete[] maxheap;
}

int main() {
    Heap H;
    H.get();
    H.displayMin();
    H.displayMax();
    return 0;
}
