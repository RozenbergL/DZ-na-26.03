#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
	string arif;
	cin >> arif;
	string answer = "";
	vector <char> stack(arif.size());
	vector <double> prov;
	int head = 0;
	for (int i = 0; i < arif.size(); i++) {
		if (arif[i] == '(') {
			stack[head] = arif[i];
			head++;
		}
		if (arif[i] == '+' || arif[i] == '-') {
			if ((head > 0) && (stack[head - 1] == '-' || stack[head - 1] == '+' || stack[head - 1] == '*' || stack[head - 1] == '/')) {
				answer += stack[head - 1];
				answer += " ";
				vector <char> stack2(arif.size());
				head--;
				for (int j = 0; j < head; j++) {
					stack2[j] = stack[j];
				}
				stack = stack2;
				stack[head] = arif[i];
				head++;
			}
			else {
				stack[head] = arif[i];
				head++;
			}
		}
		if (arif[i] == '*' || arif[i] == '/') {
			if ((head > 0) && (stack[head - 1] == '*' || stack[head - 1] == '/')) {
				answer += stack[head - 1];
				answer += " ";
				vector <char> stack2(arif.size());
				head--;
				for (int j = 0; j < head; j++) {
					stack2[j] = stack[j];
				}
				stack = stack2;
				stack[head] = arif[i];
				head++;
			}
			else {
				stack[head] = arif[i];
				head++;
			}
		}
		if (arif[i] == ')') {
			for (int j = head - 1; j >= 0; j--) {
				if (stack[j] == '(') {
					break;
				}
				head--;
				answer += stack[j];
				answer += " ";
			}
			head--;
		}
		if (arif[i] == '0' || arif[i] == '1' || arif[i] == '2' || arif[i] == '3' || arif[i] == '4' || arif[i] == '5' || arif[i] == '6' || arif[i] == '7' || arif[i] == '8' || arif[i] == '9') {
			for (int j = i; j < arif.size(); j++) {
				if (arif[j] == '(' || arif[j] == ')' || arif[j] == '+' || arif[j] == '-' || arif[j] == '*' || arif[j] == '/') {
					break;
				}
				i++;
				answer += arif[j];
			}
			i--;
			answer += " ";
		}
		vector <char> stack2(arif.size());
		for (int j = 0; j < head; j++) {
			stack2[j] = stack[j];
		}
		stack = stack2;
	}
	if (answer[answer.size() - 1] == ' ') {
		answer = answer.substr(0, answer.size() - 1);
	}
	for (int i = head; i >= 0; i--) {
		answer += stack[i];
		answer += " ";
	}
	cout << answer << endl;
	for (int i = 0; i < answer.size(); i++) {
		string num = "";
		if (answer[i] == '0' || answer[i] == '1' || answer[i] == '2' || answer[i] == '3' || answer[i] == '4' || answer[i] == '5' || answer[i] == '6' || answer[i] == '7' || answer[i] == '8' || answer[i] == '9') {
			for (int j = i; j < answer.size(); j++) {
				if (answer[j] == ' ') {
					num = answer.substr(i, j - i);
					int n = atoi(num.c_str());
					prov.push_back(n);
					i = j;
					break;
				}
			}
		}
		if (answer[i] == '+') {
			prov.push_back(0.1);
		}
		if (answer[i] == '-') {
			prov.push_back(0.2);
		}
		if (answer[i] == '*') {
			prov.push_back(0.3);
		}
		if (answer[i] == '/') {
			prov.push_back(0.4);
		}
	}
	cout << endl;
	while (prov.size() > 1) {
		for (int i = 0; i < prov.size(); i++) {
			if (prov[i] == 0.1) {
				vector <double> prov2;
				for (int j = 0; j < i - 2; j++) {
					prov2.push_back(prov[j]);
				}
				double r = prov[i - 2] + prov[i - 1];
				prov2.push_back(r);
				for (int j = i + 1; j < prov.size(); j++) {
					prov2.push_back(prov[j]);
				}
				prov = prov2;
				break;
			}
			if (prov[i] == 0.2) {
				vector <double> prov2;
				for (int j = 0; j < i - 2; j++) {
					prov2.push_back(prov[j]);
				}
				double r = prov[i - 2] - prov[i - 1];
				prov2.push_back(r);
				for (int j = i + 1; j < prov.size(); j++) {
					prov2.push_back(prov[j]);
				}
				prov = prov2;
				break;
			}
			if (prov[i] == 0.3) {
				vector <double> prov2;
				for (int j = 0; j < i - 2; j++) {
					prov2.push_back(prov[j]);
				}
				double r = prov[i - 2] * prov[i - 1];
				prov2.push_back(r);
				for (int j = i + 1; j < prov.size(); j++) {
					prov2.push_back(prov[j]);
				}
				prov = prov2;
				break;
			}
			if (prov[i] == 0.4) {
				vector <double> prov2;
				for (int j = 0; j < i - 2; j++) {
					prov2.push_back(prov[j]);
				}
				double r = prov[i - 2] / prov[i - 1];
				prov2.push_back(r);
				for (int j = i + 1; j < prov.size(); j++) {
					prov2.push_back(prov[j]);
				}
				prov = prov2;
				break;
			}
		}
	}
	for (auto now : prov) {
		cout << now << " ";
	}

}
