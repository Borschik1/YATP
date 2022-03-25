#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;
template <class T>
class Stack {
public:
	list<T> queue;
	map<int, list<T>> journal;
	int ip = 1;

	void Push(T smth) {            // o(n)
		queue.push_back(smth);
		journal[ip] = queue;
		ip++;
	}

	T Pop() {                      // o(n)
		T need = queue.back();
		queue.pop_back();
		journal[ip] = queue;
		ip++;
		return need;
	}

	void Rollback(int index) {      // o(n)
		queue = journal[index];
		journal[ip] = queue;
		ip++;
	}

	void Forget() {                 // o(1)
		journal.clear();
		ip = 1;
	}
};

void main()
{
	Stack <int> bruh;
	bruh.Push(1);
	bruh.Push(2);
	cout << bruh.Pop() << endl;
	bruh.Rollback(1);
	bruh.Rollback(4);
	cout << bruh.Pop() << endl;
	bruh.Forget();
}