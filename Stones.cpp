#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main() {
	vector <int> numbers;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		numbers.push_back(k);
	}
	int index = 0;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int ind1 = (index + 1) % n;
		int ind2 = (index + 2) % n;
		int ind3 = (index + 3) % n;
		int n1 = numbers[(index + 1) % n];
		int n2 = numbers[(index + 2) % n];
		int n3 = numbers[(index + 3) % n];
		vector <int> numbers2;
		for (int j = 0; j < n; j++) {
			if (j != ind1 && j != ind2 && j != ind3) {
				numbers2.push_back(numbers[j]);
			}
		}
		int maxi = 0;
		int ind_maxi = -1;
		for (int j = 0; j < n - 3; j++) {
			if (numbers2[j] > maxi && numbers2[j] < numbers[index]) {
				maxi = numbers2[j];
				ind_maxi = j;
			}
		}
		if (ind_maxi == -1) {
			int maxi = 0;
			for (int j = 0; j < n - 3; j++) {
				if (numbers2[j] > maxi) {
					maxi = numbers2[j];
					ind_maxi = j;
				}
			}
		}
		vector <int> numbers3;
		for (int j = 0; j <= ind_maxi; j++) {
			numbers3.push_back(numbers2[j]);
		}
		numbers3.push_back(n1);
		numbers3.push_back(n2);
		numbers3.push_back(n3);
		for (int j = ind_maxi + 1; j < n - 3; j++) {
			numbers3.push_back(numbers2[j]);
		}
		numbers = numbers3;
		index = (ind_maxi + 4) % n;
	}
	for (auto now : numbers) {
		cout << now << " ";
	}
	cout << endl;
}