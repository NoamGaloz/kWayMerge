#include "Header.h"
#include "Heap.h"
#include "HeapNode.h"

int FindSizeOfGroup(int k, int n, int& rem)
{
	int groupSize;

	groupSize = n / k;
	if(rem !=0)
	{
		groupSize++;
		rem--;
	}
	
	return groupSize;
}

int* kWayMerge(int* arr, int k, int n)
{
	if ((n < k) || (k == 1))
	{
		QuickSort(arr, 0, n - 1);
		return arr;
	}

	int* resArr = new int[n];
	Heap H(k);
	
	int idxForResArr = 0;
	int rem = n % k;
	int subArrayStartIndex = 0;
	
	for (int i = 0; i < k; i++)
	{
		int sizeOfGroup = FindSizeOfGroup(k, n, rem);
		
		int* subArray = new int[sizeOfGroup];
		memcpy(subArray, arr + subArrayStartIndex, sizeOfGroup * sizeof(int));

		HeapNode node(kWayMerge(subArray, k, sizeOfGroup), sizeOfGroup);
		H.insert(&node);
		subArrayStartIndex += sizeOfGroup;
	}
	
	for (int i = 0; i < n; i++)
	{
		resArr[i] = (H.Min()).getVal();
		try {
			H.Min().updateMinValToNext();
			H.fixHeap(0);
		}
		catch (...)
		{
			H.DeleteMin();
		}
	}

	return resArr;
}

int Partition(int* A, int first, int end)
{
		int pivot = A[end]; 
		int i = (first - 1);

		for (int j = first; j < end; j++)
		{
			if (A[j] < pivot)
			{
				i++;    // increment index of smaller element
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		int temp = A[i+1];
		A[i+1] = A[end];
		A[end] = temp;
		return (i + 1);
	
}

void QuickSort(int* A, int left, int right)
{
	int pivot;

	if(left < right)
	{
		pivot = Partition(A, left, right);
		QuickSort(A, left, pivot - 1);
		QuickSort(A, pivot + 1, right);
	}
}