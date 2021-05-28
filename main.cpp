#include "Header.h"

int main()
{
	int n,k;
	string inputFileName;
	string outputFileName;

	cout << "Please Enter How Many Number Do You Want To Sort?";
	cin >> n;
	cout << "Please Enter The Number K for K-Way MergeSort";
	cin >> k;
	cout << "Please Enter How Many Number Do You Want To Sort?";
	cin >> inputFileName;
	cout << "Please Enter How Many Number Do You Want To Sort?";
	cin >> outputFileName;

	int* arrToSort = readNumbersFromFile(inputFileName,n);
	int* sortedArr = kWayMerge(arrToSort, k, n);


}

int* readNumbersFromFile(string inputFileName, int n)
{
	ifstream inputFile;
	int* resArr = nullptr;
	inputFile.open(inputFileName);

	try {
		if (inputFile)
		{
			resArr = readNumbersToArr(inputFile, n);
		}
		else
		{
			throw 0;
		}
	}
	catch (...)
	{
		cout << "wrong Input" << endl;
		exit(1);
	}

	inputFile.close();

	return resArr;
}

int* readNumbersToArr(ifstream &inputFile,int n)
{
	int* arrToSort = new int[n];
	int arrIdx = 0;
	string numInStr;

	
	while (getline(inputFile, numInStr))
	{
		int num = stoi(numInStr); //throws exception when faild
		arrToSort[arrIdx] = num;
		arrIdx++;
	}

	if (arrIdx != n)
	{
		throw 0;
	}

	return arrToSort;
}
