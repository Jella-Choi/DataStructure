#include<iostream>
using namespace std;

class Array_Stack {
public:
	int* Stack;
	int capacity;
	int t;

	Array_Stack(int cap) {
		this->capacity = cap;
		this->Stack = new int[capacity];
		this->t = -1;
	}

	int empty() {
		return t == -1;
	}

	int top() {
		if (empty()) { return -1; }
		else { return Stack[t];	}
	}

	void push(int n) {
		if (size() == capacity) { cout << "Full\n"; }
		else {
			Stack[++t] = n;
		}
	}

	int pop() {
		if (empty()) { return -1; }
		else {
			return Stack[t--];
		}
	}

	int size() {
		return (t + 1);
	}

};

int main() {
	int n; string cmd; int st_n;
	Array_Stack st(10000);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "empty") { cout << st.empty() << "\n"; }
		else if (cmd == "top") { cout << st.top() << "\n"; }
		else if (cmd == "push") { cin >> st_n; st.push(st_n); }
		else if (cmd == "pop") { cout << st.pop() << "\n"; }
		else if (cmd == "size") { cout << st.size() << "\n"; }
	}

}