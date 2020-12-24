// This program was made by Bannikov Nikita, group 9309 
#include "Header.h"
#include <iostream>
#include <locale>

void main()
{
	BinHeap* heap = new BinHeap;

	int initial_data[] = { 9, 3, 2, 4, 10, 1, 5, 6 };

	cout << "Insert into heap values: ";
	for (int i = 0; i < (sizeof(initial_data) / sizeof(*initial_data)); i++)
	{
		int value = initial_data[i];
		cout << value << " ";
		heap->insert(value);
	}
	cout << endl;
	cout << "Values: " << endl;
	heap->print_to_console();

	heap->remove(9);
	cout << "Values after removing 9: " << endl;
	heap->print_to_console();

	heap->insert(8);
	cout << "Values after inserting 8: " << endl;
	heap->print_to_console();

	BinHeapIterator* bfIterator = heap->create_bft_iterator();
	cout << "Breadth-First Iterator:" << endl;
	while (bfIterator->hasNext()) {
		cout << bfIterator->getNext() << " ";
	}
	cout << endl;
	delete bfIterator;

	BinHeapIterator* dfIterator = heap->create_dft_iterator();
	cout << "Depth-First Iterator:" << endl;
	while (dfIterator->hasNext()) {
		cout << dfIterator->getNext() << " ";
	}
	cout << endl;
	delete dfIterator;
	delete heap;
}
