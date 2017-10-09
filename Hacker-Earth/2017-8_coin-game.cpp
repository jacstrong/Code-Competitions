/*
 * Jacob Strong
 * Written September 2017
 * https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/coin-game-3-1762eeeb/
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int turnCount = 0;
		for (int j = 0; j < N; j++) {
			int A;
			cin >> A;
			while (A % 2 == 0) {
				A /= 2;
				turnCount++;
			}
		}
		if (turnCount % 2 == 1) {
			cout << "Charlie" << endl;
		}
		else {
			cout << "Alan" << endl;
		}
	}
	return 0;
}
