#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap{

    int *harr;
    int heap_size;
    int capacity;

    public:
        MinHeap(int c);

        int left(int idx) { return (2 * idx + 1); }
        int right(int idx) { return (2 * idx + 2); }
        int parent(int idx) { return (idx - 1) / 2; }

        void insert(int no);
        void pop (int idx);
        int extractMin();
        int getMin();
        void minHeapify(int idx);
        bool empty();
};

MinHeap::MinHeap(int cap){
    this->capacity = cap;
    this->heap_size = 0;
    harr = new int[cap];
}

void MinHeap::insert(int no){

    //if capacity is full
    if(heap_size == capacity){
        cout << "Cannot insert heap is full.."<<endl;
        return;
    }
    
    heap_size += 1;
    int idx = heap_size-1;
    harr[heap_size-1] = no;
  
    // cout << "heap_size " << heap_size << endl;

    while(idx > 0 and harr[parent(idx)] > harr[idx]){
        swap(harr[parent(idx)], harr[idx]);
        idx = parent(idx);
    }
    return;
}

void MinHeap :: minHeapify(int idx){

    int l = left(idx);
    int r = right(idx);

    int smallest = idx;

    if(l < heap_size and harr[l] < harr[idx]){
        smallest = l;
    }
    if(r < heap_size and harr[r] < harr[smallest]){
        smallest = r;
    }

    if(smallest != idx){
        swap(&harr[idx],&harr[smallest]);
        minHeapify(smallest);
    }
    return;
}

int MinHeap::getMin(){
    return harr[0];
}

int MinHeap::extractMin(){

    if(heap_size == 0){
        cout << "Underflow.. no element to pop.." << endl;
        return INT_MAX;
    }

    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }

    int top = harr[0];

    harr[0] = harr[heap_size - 1];
    heap_size--;
    minHeapify(0);
    return top;
}

void MinHeap::pop(int idx){

    if(idx >= heap_size){
        cout << "There is no element at index "<<idx<<".This is out of the array"<< endl;
        return;
    }
    // cout << "heap_size " << heap_size << endl;
    if(heap_size == 0){
        cout << "Underflow... No elements to pop.. :(\n";
        return;
    }
    if(heap_size == 1){
        heap_size--;
        return;
    }

    harr[idx] = INT_MIN;

    while(idx >0 and harr[parent(idx)] > harr[idx] ){
        swap(harr[parent(idx)], harr[idx]);
        idx = parent(idx);
    }
    int deletedElement = extractMin();
    return;
}

bool MinHeap::empty(){
    return heap_size == 0;
}

int main(){

    MinHeap h(10);

    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(5);

    // while (!h.empty()){
    //     int top = h.extractMin();
    //     if(top != INT_MAX){
    //         cout << top << " ";
    //     }
    // }
    // cout << endl;

    h.pop(2);
    h.pop(4);
    cout << h.getMin() << endl;
    while (!h.empty())
    {
        int top = h.extractMin();
        if(top != INT_MAX){
            cout << top << " ";
        }
    }

    return 0;
}