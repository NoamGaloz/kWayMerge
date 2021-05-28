#pragma once
#include <algorithm>
#include "HeapNode.h"
using namespace std;

namespace H {
	class Heap
	{
	public:
		Heap(int size);
		Heap(HeapNode* arr, int size); // BuildHeap according to floyd algorytem.
		~Heap() { if (isAllocated) delete[] data; data = nullptr; };
		void insert(HeapNode* item);
		void fixHeap(int node);
		HeapNode& Min();
		HeapNode* DeleteMin();

		int getLeft(int node) const;
		int getRight(int node) const;
		int getParent(int node) const;

	private:
		HeapNode* data;
		int physSize;
		int logSize;
		bool isAllocated;
	};

	void swap(HeapNode* node1, HeapNode* node2);

}
