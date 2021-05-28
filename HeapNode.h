#pragma once


class HeapNode
{
public:

	HeapNode()
	{
	}

	HeapNode(int* arr, int size)
	{
		m_Arr = arr;
		m_MinVal = arr[0];
		m_currMinValIdx = 0;
		m_Size = size;
	}

	int getVal()
	{
		return m_MinVal;
	}

	int* getArr()
	{
		return m_Arr;
	}

	void updateMinValToNext()
	{
		m_currMinValIdx++;
		if (m_currMinValIdx = m_Size)
			throw new exception("Arr end");
		m_MinVal = m_Arr[m_currMinValIdx];
	}

private:
	int* m_Arr;
	int m_MinVal;
	int m_currMinValIdx;
	int m_Size;

}