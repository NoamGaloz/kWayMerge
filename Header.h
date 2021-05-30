#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <istream>
#include <string>
# include  "Heap.h"

using namespace std;
using namespace heap;

int FindSizeOfGroup(int k, int n, int& rem);
void WriteArrayToFile(int* arr, int size, string fileName);
int* readNumbersFromFile(string inputFileName, int n);
int* kWayMerge(int* arr, int k, int n);
int* readNumbersToArr(ifstream &inputFile,int n);
int Partition(int* A, int first, int end);
void QuickSort(int* A, int left, int right);
void CheckAllDigits(string numInStr);