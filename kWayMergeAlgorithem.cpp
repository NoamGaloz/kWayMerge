#include "Header.h"
#include "Heap.h"
#include "HeapNode.h"
using namespace H;
#define SUBARRAYSIZE n/k

int* kWayMerge(int* arr, int k, int n)
{
	if (n < k)
	{
		cout << "call quicksort" << endl;
		return arr;
	}

	int* resArr = new int[n];

	 Heap H(k);
	int idxForResArr = 0;

	for (int i = 0; i < k ; i++)
	{
		int* subArray = new int[SUBARRAYSIZE];
		memcpy(subArray, arr, SUBARRAYSIZE);

		HeapNode node(kWayMerge(subArray,k, SUBARRAYSIZE), SUBARRAYSIZE);
		H.insert(&node);
	}

	for (int i = 0; i < n; i++)
	{
		resArr[i] = (H.Min()).getVal();
		try {
			H.Min().updateMinValToNext();
			H.fixHeap(0);
		}
		catch(...)
		{
			H.DeleteMin();
		}
	}

	return resArr;


}