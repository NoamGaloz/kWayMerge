#include "Header.h"

int main()
{
	int n,k;
	string inputFileName;
	string outputFileName;

	cout << "Please Enter How Many Number Do You Want To Sort: ";
	cin >> n;
	cout << "Please Enter The Number K for K-Way MergeSort: ";
	cin >> k;
	cout << "Please Enter Input file name: ";
	cin >> inputFileName;
	cout << "Please Enter Output file name: ";
	cin >> outputFileName;

	int* arrToSort = readNumbersFromFile(inputFileName,n);
	
	/*int A[9] = { 2,-4,3,0,17,5,30,1,9 };
	int B[7] = { 2,-4,3,0,17,5,30};
	int C[16] = { 2,-4,-4,2,17,5,30,1,4,8,-21,13,42,-5,19,17};
	int D[8] = { 0,0,3,-6,-230,44,-3,-1};*/
	
	int* sortedArr = kWayMerge(arrToSort, k,n);


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
		throw exception();
	}

	return arrToSort;
}
