#include <iostream>
#include <list>
#include <string>

using namespace std;

int priority(char symb) {
	if (symb == '+' || symb == '-') {
		return 0;
	}
	else if (symb == '*' || symb == '/') {
		return 1;
	}
	else if (symb == '^') {
		return 2;
	}
	else {
		return -1;
	}
}

int evaluate(string str) {
	list <float> stack;
	int need1, need2;
	for (int i = 0; i < str.length(); ++i) {
		if (isdigit(str[i])) {
			stack.push_back(str[i] - '0');
		}
		else {
			need1 = stack.back();
			stack.pop_back();
			need2 = stack.back();
			stack.pop_back();
			switch (str[i]) {
			case '+':
				stack.push_back(need1 + need2);
				break;
			case '-':
				stack.push_back(need1 - need2);
				break;
			case '*':
				stack.push_back(need1 * need2);
				break;
			case '/':
				stack.push_back((float)need1 / need2);
				break;
			case '^':
				stack.push_back(pow(need1, need2));
				break;
			}
		}
	}
	return stack.back();
}

void main()
{
	string inputData, answer = "";
	list <char> stack;
	cin >> inputData;
	for (int i = 0; i < inputData.length(); ++i) {
		if (isdigit(inputData[i])) {
			answer += inputData[i];
		}
		else {
			if (inputData[i] == '(') {
				stack.push_back(inputData[i]);
				continue;
			} if (inputData[i] == ')') {
				while (stack.back() != '(') {
					answer += stack.back();
					stack.pop_back();
				}
				stack.pop_back();
				continue;
			}
			if (stack.size() != 0) {
				if (priority(inputData[i]) <= priority(stack.back())) {
					answer += stack.back();
					stack.pop_back();
					stack.push_back(inputData[i]);
					continue;
				}
			}
			stack.push_back(inputData[i]);
		}
	}
	while (stack.size() > 0) {
		answer += stack.back();
		stack.pop_back();
	}
	cout << answer << endl;
	cout << evaluate(answer);
}
