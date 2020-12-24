// This program was made by Bannikov Nikita, group 9309 
#include "Header.h"
#include <iomanip>
#include <iostream>

using namespace std;

void BinHeap::heapify(int index) {
    int stored_val;
    int leftChild  = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap_arr.size()) {
        if (heap_arr[index] < heap_arr[leftChild]) {
            stored_val = heap_arr[index];
            heap_arr[index] = heap_arr[leftChild];
            heap_arr[leftChild] = stored_val;
            heapify(leftChild);
        }
    }

    if (rightChild < heap_arr.size()) {
        if (heap_arr[index] < heap_arr[rightChild]) {
            stored_val = heap_arr[index];
            heap_arr[index] = heap_arr[rightChild];
            heap_arr[rightChild] = stored_val;
            heapify(rightChild);
        }
    }
}

void BinHeap::insert(int key) {
    int index, parent;
    index = (int) heap_arr.size();
    heap_arr.push_back(key);
    parent = (index - 1) / 2;
    while (parent >= 0 && index > 0) {
        if (heap_arr[index] > heap_arr[parent]) {
            int stored_val = heap_arr[index];
            heap_arr[index] = heap_arr[parent];
            heap_arr[parent] = stored_val;
         }
         index = parent;
         parent = (index - 1) / 2;
    }
}

BinHeap::BreadthFirstBinHeapIterator::BreadthFirstBinHeapIterator(BinHeap* binary_heap) {
    current = 0;
    heap = binary_heap;
}

BinHeap::DepthFirstBinHeapIterator::DepthFirstBinHeapIterator(BinHeap* binary_heap) {
    current = 0;
    heap = binary_heap;
    int heap_size = (int) heap->heap_arr.size();
    visited_nodes = new bool[heap_size];
    for (int i = 0; i < heap_size; i++) {
        visited_nodes[i] = false;
    }
}

bool BinHeap::contains(int key) {
    for (int i = 0; i < heap_arr.size(); i++) {
        if (heap_arr[i] == key) {
            return true;
        }
    }
    return false;
}

void BinHeap::remove(int key) {
    for (int i = 0; i < heap_arr.size(); i++) {
        if (heap_arr[i] == key) {
            heap_arr[i] = heap_arr[heap_arr.size() - 1];
            heap_arr.pop_back();
            heapify(i);
            break;
        }
    }
}

/* Supported method */
void BinHeap::print_to_console() {
    for (int i = 0; i < heap_arr.size(); i++) {
        cout << heap_arr[i] << " ";
    }
    cout << endl;
}
