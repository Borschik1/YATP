#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;


void main()
{ 
	int n, m, ip = 0, need1, need2, need3;
	cin >> n;
	vector <int> vect(n);
	for (int i = 0; i < n; ++i) {
		cin >> vect[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		need1 = vect[ip];
		need2 = vect[(ip + 1 + n) % n];
		need3 = vect[(ip + 2 + n) % n];
		vect[ip] = 0;
		vect[(ip + 1 + n) % n] = 0;
		vect[(ip + 2 + n) % n] = 0;
		int ind = 0;
		if (need1 == 1 || (need1 == 2 && (need2 == 1 || need3 == 1)) || ((need1 == 3 && (need2 + need3 == 3)))) {
			for (int j = 0; j < n; ++j) {
				if (vect[j] > vect[ind]) {
					ind = j;
				}
			}
		}
		else {
			for (int j = 0; j < n; ++j) {
				if (vect[j] < need1 && vect[j] > vect[ind]) {
					ind = j;
				}
			}
		}
		while (ip != ind) {
			vect[(ip + 2 + n) % n] = vect[(ip - 1 + n) % n];
			ip = (ip - 1 + n) % n;
		}
		vect[ind] = need1;
		vect[(ind + 1 + n) % n] = need2;
		vect[(ind + 2 + n) % n] = need3;
		ip = (ip + 3 + n) % n;
		//cout << ip << " " << vect[0] << " " << vect[1] << " " << vect[2] << endl;
	}
	for (int i = 0; i < n; ++i) {
		cout << vect[i] << " ";
	}
} 