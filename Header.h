// This program was made by Bannikov Nikita, group 9309 
#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class BinHeapIterator
{
public:
	/* Get next node */
	virtual int getNext() = 0;
	/* Check if next node exists */
	virtual bool hasNext() = 0;
};

class BinHeap
{
	/* Keeps the heap */
	vector<int> heap_arr;

public:
	
	BinHeap() {
		heap_arr = {};
	}

	~BinHeap() {
		heap_arr.clear();
	}
	
	/* Methods */
	void insert(int);
	bool contains(int);
	void remove(int);

	/* Supported methods */
	void print_to_console();
	void heapify(int);


	/* Iterators implementation */
	class BreadthFirstBinHeapIterator : public BinHeapIterator 	{
		int current;
		BinHeap* heap;

	public:
		BreadthFirstBinHeapIterator(BinHeap* binary_heap);

		int getNext() override {
			if (!hasNext()) {
				throw out_of_range("out of nodes");
			}
			return heap->heap_arr[current++];
		}

		bool hasNext() override { 
			return heap->heap_arr.size() > current;
		}
	};

	BinHeapIterator* create_bft_iterator() {
		return new BreadthFirstBinHeapIterator(this);
	}


	class DepthFirstBinHeapIterator : public BinHeapIterator {
		int current;
		BinHeap* heap;
		bool* visited_nodes;

	public:
		DepthFirstBinHeapIterator(BinHeap* binary_heap);

		int getNext() override {
			if (!hasNext())  {
				throw out_of_range("out of nodes");
			}
			int previous = current;
			visited_nodes[previous] = true;

			if (!hasNext()) {
				return heap->heap_arr[previous];
			}

			int leftChild, rightChild;
			for (;;)
			{
				leftChild  = current * 2 + 1;
				rightChild = current * 2 + 2;

				if (leftChild < heap->heap_arr.size()) {
					if (!visited_nodes[leftChild]) {
						current = leftChild;
						break;
					}
				}

				if (rightChild < heap->heap_arr.size()) {
					if (!visited_nodes[rightChild]) {
						current = rightChild;
						break;
					}
				}
				/* Parent*/
				current = (current - 1) / 2;
			}
			return heap->heap_arr[previous];
		}

		bool hasNext() override {
			if (heap->heap_arr.empty()) {
				return false;
			}
			int index = current;
			int leftChild, rightChild;
			for(;;) {
				leftChild = (index * 2) + 1;
				rightChild = (index * 2) + 2;

				if (leftChild < heap->heap_arr.size()) {
					if (!visited_nodes[leftChild]) {
						return true;
					}
				}

				if (rightChild < heap->heap_arr.size()) {
					if (!visited_nodes[rightChild]) {
						return true;
					}
				}

				if (index != 0) {
					/* Parent*/
					index = (index - 1) / 2;
				}
				else if (!visited_nodes[index]) {
					return true;
				}
				else {
					return false;
				}
			}
		}

		~DepthFirstBinHeapIterator() {
			delete[] visited_nodes;
		}
	};

	BinHeapIterator* create_dft_iterator() {
		return new DepthFirstBinHeapIterator(this);
	}
};
