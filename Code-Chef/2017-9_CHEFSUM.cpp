/*
 * Jacob Strong
 * Written September 2017
 * https://www.codechef.com/SEPT17/problems/CHEFSUM/
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
	//std::scanf("%u", &numCases);

	std::vector<std::vector<int>> testCases;

	unsigned arrSize;
	int temp;

	for (unsigned i = 0; i < numCases; i++) 
	{
		testCases.push_back(std::vector<int>());

		std::cin >> arrSize;
		//std::scanf("%u", &arrSize);

		for (unsigned j = 0; j < arrSize; j++) 
		{
			std::cin >> temp;
			//std::scanf("%i", &temp);
			testCases[i].push_back(temp);
		}
	}

	return testCases;
}

void calcMinVal(const std::vector<int> &testCases) {
	/*
	std::vector<int> sum;
	
	int sufSum = 0;
	for (unsigned i = 0; i < testCases.size(); i++)
	{
		sufSum += testCases[i];
	}
	
	int preSum = testCases[0];
	
	int tempIndex = 0;

	//sum.push_back(preSum + totalSum);
	//int tempMin = sum[0];
	int tempMin = preSum + sufSum;

	for (unsigned i = 1; i < testCases.size(); i++)
	{
		preSum += testCases[i];
		sufSum -= testCases[i - 1];
		//sum.push_back((preSum)+(totalSum));

		if (tempMin > (preSum + sufSum)){
		//if (tempMin > sum[i]){
			//tempMin = sum[i];
			tempMin = (preSum + sufSum);
			tempIndex = i;
		}

	}

	*/

	
	int tempIndex = 0;
	long long sum = 0;
	long long tempMin;
	std::vector<long long> tempVec;
	for (size_t i = 0; i < testCases.size(); i++) {
		sum += testCases[i];
		tempVec.push_back(sum);
	}
	//sum = 0;
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
	
	/*
	for (size_t i = 0; i < testCases.size(); i++) {
		preSum += testCases[i];
		if (i != 0) {
			sum -= testCases[i - 1];
		}
		tempVec.push_back(preSum + sum);

		if (i == 0) {
			tempMin = tempVec[i];
		}

		if (tempMin > tempVec[i]) {
			tempIndex = i - 1;
		}
	}
	*/

	std::cout << tempIndex + 1;
}