/*
 * Jacob Strong
 * Written October 2017
 * https://www.codechef.com/OCT17/problems/PERFCONT/
 */

#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int T;
	cin >> T;
	for (size_t i = 0; i < T; i++) {
		int N;
		cin >> N;
		long long P;
		cin >> P;
		long long problem = 0;
		int cakewalk = 0;
		int hard = 0;
		for (size_t j = 0; j < N; j++) {
			cin >> problem;
			if (problem >= P/2){
				cakewalk++;
			} else if (problem <= P/10){
				hard++;
			}
		}
		if (hard == 2 && cakewalk == 1){
			cout << "yes" << endl;
		} else{
			cout << "no" << endl;
		}

	}
	return 0;
}