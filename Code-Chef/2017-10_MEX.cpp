/*
 * Jacob Strong
 * Written October 2017
 * https://www.codechef.com/OCT17/problems/MEX
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int T;
	cin >> T;

	for (int i = 0; i < T; i++){
		int N;
		cin >> N;
		int K;
		cin >> K;
		int temp;
		vector<int> S(200000); // 200000 is the constraint value for S
		fill(S.begin(), S.end(), 0);
		for (int j = 0; j < N; j++) {
			cin >> temp;
			S[temp] = 1;
		}

		int count = 0;
		int itterator = 0;
		if (K == 0){
			while(itterator < S.size() && S[itterator] == 1){
				count++;
				itterator++;
			}
		}
		else {
			while (K >= 0) {
				if (S.size() > itterator) {
					if(S[itterator] == 1){
						count++;
						itterator++;
					} else{
						if (K > 0) {
							count++;
						}
						K--;
						itterator++;
					}
				} else{
					if (K > 0) {
						count++;
					}
					K--;
					itterator++;
				}
			}
		}
		if(count >= S[0]){
			cout << count << endl;;
		} else{
			cout << 0 << endl;
		}
	}

	return 0;
}