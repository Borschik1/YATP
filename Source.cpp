#include <iostream>
#include <list>
#include <string>

using namespace std;
template <class T>
class Queue {
public:
	list <T> queue;

	void push(T smth) {
		queue.push_back(smth);
	}

	T pop() {
		T need = queue.front();
		queue.pop_front();
		return need;
	}
};

void main()
{
}