/*
 * Jacob Strong
 * Written September 2017
 * https://www.codechef.com/SEPT17/problems/MINPERM/
 */

#include <iostream>
#include <vector>

std::vector<int> readInput();
void permOutput(int test);

int main(void) {
	std::vector<int> testCases = readInput();
	for (int i = 0; i < testCases.size(); i++)
	{
		permOutput(testCases[i]);
		std::cout << std::endl;
	}

	return 0;
}

std::vector<int> readInput() {
	int testNum;
	std::cin >> testNum;
	std::vector<int> testCases;
	int temp;
	for (int i = 0; i < testNum; i++)
	{
		std::cin >> temp;
		testCases.push_back(temp);
	}
	return testCases;
}

void permOutput(int test) {
	for (int i = 0; i < test; i++)
	{
		if (test % 2 == 1 && i + 2 == test)
		{
			std::cout << test << " ";
			std::cout << test - 2 << " ";
			break;
		}
		else
		{
			if ((i + 1) % 2 == 1)
			{
				std::cout << i + 2 << " ";
			}
			else
			{
				std::cout << i << " ";
			}
		}
	}
}