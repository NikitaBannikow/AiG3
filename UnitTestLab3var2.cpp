// This program was made by Bannikov Nikita, group 9309 
#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../AlgorithmLab3var2/Header.h"
#include "../AlgorithmLab3var2/Implementation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab3
{
	TEST_CLASS(UnitTestLab3var2)
	{
	public:
		BinHeap* binaryHeap;

		UnitTestLab3var2() {
			Logger::WriteMessage(">> UnitTestLab3var2, ");
			binaryHeap = new BinHeap;
		}

		~UnitTestLab3var2() {
			Logger::WriteMessage(" >> ~UnitTestLab3var2");
			delete binaryHeap;
		}

		TEST_METHOD(insert_2h)
		{
			int initial_data[] = { 2, 3, 9 };
			insert_data(&initial_data[0], 3);
			int result_data[] = { 9, 2, 3 };
			check_result(&result_data[0], 3);
		}

		TEST_METHOD(insert_3h)
		{
			int initial_data[] = { 2, 3, 9 };
			insert_data(&initial_data[0], 3);

			binaryHeap->insert(4);

			int result_data[] = { 9, 4, 3, 2 };
			check_result(&result_data[0], 4);
		}

		TEST_METHOD(remove_middle)
		{
			int initial_data[] = { 2, 3, 9, 4, 10, 8 };
			insert_data(&initial_data[0], 6);

			binaryHeap->remove(9);

			int result_data[] = { 10, 4, 8, 2, 3 };
			check_result(&result_data[0], 5);
		}

		TEST_METHOD(remove_first)
		{
			int initial_data[] = { 2, 3, 9, 4, 10, 8 };
			insert_data(&initial_data[0], 6);

			binaryHeap->remove(10);

			int result_data[] = { 9, 4, 8, 2, 3 };
			check_result(&result_data[0], 5);
		}

		TEST_METHOD(remove_last)
		{
			int initial_data[] = { 2, 3, 9, 4, 10, 8 };
			insert_data(&initial_data[0], 6);

			binaryHeap->remove(10);
			binaryHeap->remove(3);

			int result_data[] = { 9, 4, 8, 2};
			check_result(&result_data[0], 4);

			binaryHeap->insert(0);

			int result_data2[] = { 9, 4, 8, 2, 0 };
			check_result(&result_data2[0], 5);

			binaryHeap->remove(0);

			int result_data3[] = { 9, 4, 8, 2};
			check_result(&result_data3[0], 4);
		}

		TEST_METHOD(contains)
		{
			int initial_data[] = { 2, 3, 9, 4, 10, 8 };
			insert_data(&initial_data[0], 6);

			BinHeapIterator* iterator = binaryHeap->create_bft_iterator();
			for (int i = 0; i < (sizeof(initial_data) / sizeof(*initial_data)); i++) {
				Assert::AreEqual(true, binaryHeap->contains(4));
			}
			delete iterator;
		}

		TEST_METHOD(breadth_first_iterator)
		{
			int initial_data[] = { 9, 3, 2, 4, 10, 1, 5, 6 };
			insert_data(&initial_data[0], 8);

			int result_data[] = { 10, 9, 5, 6, 4, 1, 2, 3 };

			BinHeapIterator* iterator = binaryHeap->create_bft_iterator();

			for (int i = 0; i < 8; i++) {
				int etalon = result_data[i];
				int data = iterator->getNext();
				Assert::AreEqual(etalon, data);
			}
			delete iterator;
		}
		
		TEST_METHOD(depth_first_iterator)
		{
			int initial_data[] = { 9, 3, 2, 4, 10, 1, 5, 6 };
			insert_data(&initial_data[0], 8);

			int result_data[] = { 10, 9, 6, 3, 4, 5, 1, 2 };

			BinHeapIterator* iterator = binaryHeap->create_dft_iterator();

			for (int i = 0; i < 8; i++) {
				int etalon = result_data[i];
				int data = iterator->getNext();
				Assert::AreEqual(etalon, data);
			}

			delete iterator;
		}

	private:
		void insert_data(int* data, int len) {
			for (int i = 0; i < len; i++) {
				int value = data[i];
				binaryHeap->insert(value);
			}
		}

		void check_result(int* test_data, int len) {
			BinHeapIterator* iterator = binaryHeap->create_bft_iterator();

			for (int i = 0; i < len; i++) {
				int etalon = test_data[i];
				int data = iterator->getNext();
				Assert::AreEqual(etalon, data);
			}

			delete iterator;
		}
	};
}
