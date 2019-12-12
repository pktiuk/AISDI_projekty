#include <iostream>
#include <heap.hpp>
#include <visualization.hpp>

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;
    Heap4<int,int> heap;
    heap.insert(5,10);
    cout<< heap.heap[0].first << " "<< heap.heap[0].second<<"\n";
    cout<<"heap\n";
    visualizeHeap(heap);
}