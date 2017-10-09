/* 
 * Jacob Strong
 * Written Spetember 2017
 * https://www.codechef.com/SEPT17/problems/CHEFPDIG/
 */

#include <iostream>
#include <vector>
#include <string>

void readInputs(std::vector<std::string> &testCases);
void placeChar(std::string &outputS, int &tempI);
int wasTested(std::vector<int> &tested, int num);

int main(void) {
	// read inputs
	std::vector<std::string> testCases;
	readInputs(testCases);

	int tempIone;
	int tempItwo;
	int tempI;
	std::string outputS;
	// calculate possible numbers
	for (int i = 0; i < testCases.size(); i++)
	{
		outputS.clear();
		std::vector<int> testedJ;
		for (int j = 0; j < testCases[i].size(); j++)
		{
			std::vector<int> testedK;
			if (wasTested(testedJ, (int)testCases[i][j] - '0'))
			{
				for (int k = j + 1; k < testCases[i].size(); k++)
				{

					if (wasTested(testedK, (int)testCases[i][k] - '0'))
					{
						testedK.push_back((int)testCases[i][k] - '0');
						tempIone = (int)testCases[i][j] - '0';
						tempItwo = (int)testCases[i][k] - '0';
						tempI = tempIone + (tempItwo * 10);
						if (tempI >= 65 && tempI <= 90) // A = 65, Z = 90
						{
							//tempC = (char)tempI;
							placeChar(outputS, tempI);
						}

						if (tempIone + (tempItwo * 10) != tempItwo + (tempIone * 10))
						{
							tempI = tempItwo + (tempIone * 10);
							if (tempI >= 65 && tempI <= 90)
							{
								//tempC = (char)tempI;
								placeChar(outputS, tempI);
							}
						}
						if (testedK.size() == 10)
							break;
					}
				}
				testedJ.push_back((int)testCases[i][j] - '0');
				if (testedJ.size() == 10)
					break;
			}



		}
		std::cout << outputS << std::endl;
	}  
	return 0;
}

void readInputs(std::vector<std::string> &testCases) {
	int numCases;
	std::cin >> numCases;

	std::string temp;
	for (int i = 0; i < numCases; i++)
	{
		std::cin >> temp;
		testCases.push_back(temp);
	}
}

void placeChar(std::string &outputS, int &tempI) {
	if (outputS.size() == 0)
	{
		outputS.push_back((char)tempI);
	}
	else
	{
		for (int i = 0; i < outputS.size(); i++)
		{
			if (outputS[i] == tempI)
			{
				return;
			}
			else if(outputS[i] > tempI)
			{
				std::string tempC;
				tempC.push_back((char)tempI);
				outputS.insert(i,tempC);
				return;
			}
		}
		outputS.push_back((char)tempI);
	}
}

int wasTested(std::vector<int>& tested, int num) {
	for (int i = 0; i < tested.size(); i++)
	{
		if (tested[i] == num)
		{
			return 0;
		}
	}

	return 1;
}
