#pragma once

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <istream>
#include <string>
using namespace std;

int* readNumbersFromFile(string inputFileName, int n);
int* readNumbersToArr(ifstream &inputFile,int n);