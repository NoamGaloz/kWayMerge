#include "Heap.h"

namespace H {

	Heap::Heap(int size)
	{
		data = new HeapNode[size];
		physSize = size;
		logSize = 0;
		isAllocated = true;
	}

	Heap::Heap(HeapNode* arr, int size)
	{
		logSize = physSize = size;
		data = arr;
		isAllocated = false;

		for (int i = size / 2 - 1; i >= 0; i--)
			fixHeap(i);
	}

	//inserts an item to the heap 
	void Heap::insert(HeapNode* item)
	{
		if (physSize == logSize) throw "not enough space in arr";

		int i = logSize;
		logSize++;

		while ((i > 0) && (data[getParent(i)].getVal() > item->getVal()))
		{
			data[i] = data[getParent(i)];
			i = getParent(i);
		}

		data[i] = *item;
	}

	//fix the heap which node is her root , according to FLOYD algoritem
	void Heap::fixHeap(int node)
	{
		int min = 0;
		int left = getLeft(node);
		int right = getRight(node);

		if ((left < logSize) && (data[left].getVal() < data[node].getVal()))
			min = left;
		else min = node;
		if ((right < logSize) && (data[right].getVal() < data[min].getVal()))
			min = right;

		if (min != node)
		{
			swap(&data[node], &data[min]);
			fixHeap(min);
		}
	}


	void swap(HeapNode* node1, HeapNode* node2)
	{
		HeapNode* temp = new HeapNode();
		*temp = *node1;
		*node1 = *node2;
		*node2 = *temp;
	}

	//returns the minimum- the first in the arr
	HeapNode& Heap::Min()
	{
		return data[0];
	}

	//returns the minimun and fixes the heap using fixHeap function.
	HeapNode* Heap::DeleteMin()
	{
		HeapNode* saveMin = new HeapNode();
		(*saveMin) = data[0];
		logSize--;
		data[0] = data[logSize];
		fixHeap(0);
		return saveMin;
	}


	int Heap::getLeft(int node) const
	{
		return (2 * node + 1);
	}

	int Heap::getRight(int node) const
	{
		return  (2 * node + 2);
	}

	int Heap::getParent(int node) const
	{
		return ((node - 1) / 2);
	}
}
