/*
 * Heap Sort, Page 160 (CLRS section 6.4)
 * @author Anup Agarwal
 */

#include <iostream>
#include <climits>

using namespace std;

void swap(int*,int*);

class MinHeap{

    int heapSize;
    int heapCapacity;

    public:

    int* harr;

        void showHeap();

        int left(int i){return 2*i+1;}
        int right(int i){return 2*i+2;}
        int parent(int i){return (i-1)/2;}
        int getMin(){return harr[0];}

        MinHeap(int);
        void decreaseKey(int, int); //UpHeap O(log(n))
        void minHeapify(int); //DownHeap O(log(n))
        void insertKey(int);
        void deleteKey(int);
        int extractMin();
        int getHeapSize(){return heapSize;}
};

MinHeap::MinHeap(int capacity){
    harr = new int[capacity];
    heapCapacity = capacity;
    heapSize = 0;
}

void MinHeap::decreaseKey(int i, int newValue){
//Decrease value at a given Key
//Makes sense only if newValue is smaller than harr[i]

    harr[i]=newValue;
    while(i!=0 && harr[parent(i)]>harr[i]){
        swap(&harr[parent(i)],&harr[i]);
        i=parent(i);
    }
}

void MinHeap::minHeapify(int source){
//Makes sense only if source has value greater than a child

    int l = left(source);
    int r = right(source);
    int smallestIndex = source;
    if(l<heapSize && harr[l]<harr[smallestIndex])
        smallestIndex=l;
    if(r<heapSize && harr[r]<harr[smallestIndex])
        smallestIndex=r;
    if(smallestIndex!=source){
        swap(&harr[smallestIndex],&harr[source]);
        minHeapify(smallestIndex);
    }
}

void swap(int *x, int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int MinHeap::extractMin(){

    if(heapSize==0){
        cout<<"\nUnderflow";
        return INT_MIN;
    }
    else if(heapSize==1){
        heapSize--;
        return harr[0];
    }
    else{
        int root = harr[0];
        swap(&harr[0], &harr[heapSize-1]);
        heapSize--;
        minHeapify(0);
        return root;
    }
}

void MinHeap::insertKey(int value){

    if(heapSize==heapCapacity){
        cout<<"\nOverflow!";
    }
    else{
        heapSize++;
        decreaseKey(heapSize-1, value);
    }
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::showHeap(){
    cout<<"\n\n";
    for(int i = 0; i<heapSize; i++)
        cout<<harr[i]<<" ";
}

//Test Case
int main()
{

    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    //cout<<h.getHeapSize()<<endl;

    while(h.getHeapSize()){
        cout<<h.extractMin()<<" ";
    }
    return 0;
}
