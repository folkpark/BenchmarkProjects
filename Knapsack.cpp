// Knapsack.cpp : Defines the entry point for the console application.
//

# include "stdafx.h"
# include <stdio.h>
# include <math.h>
# include <iostream>
# include <chrono>
# include <fstream>
# include <vector>

using namespace std::chrono;
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }


int main()
{

	ifstream valuesFile;
	valuesFile.open("KnapsackValues.txt");
	vector<int> valueVector;
	int valNum;
	while (valuesFile >> valNum)
	{
		valueVector.push_back(valNum);
	}

	ifstream weightsFile;
	weightsFile.open("KnapsackWeights.txt");
	vector<int> weightVector;
	int wtNum;
	while (weightsFile >> wtNum)
	{
		weightVector.push_back(wtNum);
	}

	int* val = &valueVector[0];
	int* wt = &weightVector[0];

	int  W = 5000;

	int** K = new int*[1001];
	for (int i = 0; i < 1001; i++) {
		K[i] = new int[5001];
	}

	//int n = sizeof(val) / sizeof(val[0]);
	int n = 1000;
	int trials = 100;
	int i, w;

	for (int p = 0; p < trials; p++) 
	{

		//Start Time
		high_resolution_clock::time_point startTime = high_resolution_clock::now();

		// Build table K[][] in bottom up manner
		for (i = 0; i <= n; i++)
		{
			for (w = 0; w <= W; w++)
			{
				if (i == 0 || w == 0)
					K[i][w] = 0;
				else if (wt[i - 1] <= w)
					K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
				else
					K[i][w] = K[i - 1][w];
			}
		}
		//int n = K[n][W];
		high_resolution_clock::time_point endTime = high_resolution_clock::now();//End Time
		auto duration = duration_cast<microseconds>(endTime - startTime).count();
		cout << duration << endl; //Print Execution time
		
	}


	cin.get();
    return 0;
}




