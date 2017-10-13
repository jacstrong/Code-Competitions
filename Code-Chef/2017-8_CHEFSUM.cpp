/*
 * Jacob Strong
 * Written September 2017
 * https://www.codechef.com/SEPT17/problems/CHEFSUM/
 * 
 *  NOTE: After the competition I realized that this problem could be solved
 *  way simpler.  I went the long way around and added everything up and compared
 *  all the values adding up the prefix and suffix sums.  Turns out you can
 *  solve this by just finding the minimum value and returning it.
 *  I have here the origional code (the stupid way to solve it).
 */

#include <iostream>
#include <vector>

std::vector<std::vector<int>> readInputData();
void calcMinVal(const std::vector<int> &testCases);

int main(void) {
	
	std::vector<std::vector<int>> testCases;
	
	testCases = readInputData();

	for (unsigned i = 0; i < testCases.size(); i++)
	{
		calcMinVal(testCases[i]);
		std::cout << std::endl;
	}

	int yomama;
	std::cin >> yomama;
	return 0;
}

std::vector<std::vector<int>> readInputData()
{
	unsigned numCases;
	std::cin >> numCases;

	std::vector<std::vector<int>> testCases;

	unsigned arrSize;
	int temp;

	for (unsigned i = 0; i < numCases; i++) 
	{
		testCases.push_back(std::vector<int>());

		std::cin >> arrSize;

		for (unsigned j = 0; j < arrSize; j++) 
		{
			std::cin >> temp;
			testCases[i].push_back(temp);
		}
	}

	return testCases;
}

void calcMinVal(const std::vector<int> &testCases) {
	
	int tempIndex = 0;
	long long sum = 0;
	long long tempMin;
	std::vector<long long> tempVec;
	for (size_t i = 0; i < testCases.size(); i++) {
		sum += testCases[i];
		tempVec.push_back(sum);
	}
	tempMin = sum + testCases[0];
	tempIndex = 0;
	for (size_t i = 1; i < testCases.size(); i++) {
		sum -= testCases[i-1];
		tempVec[i] += sum;
		if (tempMin > tempVec[i]) {
			tempMin = tempVec[i];
			tempIndex = i;
		}
	}

	std::cout << tempIndex + 1;
}