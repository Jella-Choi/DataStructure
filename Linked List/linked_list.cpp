#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Linked {
	Node* head;

public:
	Linked() {
		head = NULL;
	}

	void addFront(int);
	int removeFront();
	int front();
	int empty();
};

int Linked::empty() {
	return (head == NULL);
}

void Linked::addFront(int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;

	if (empty()) {
		head = newnode;
	}
	else {
		newnode->next = head;
		head = newnode;
	}
}

int Linked::removeFront() {
	if (empty()) { return -1; }
	else {
		int tmp = head->data;
		head = head->next;
		return tmp;
	}
}

int Linked::front() {
	if (empty()) { return -1; }
	else { return head->data; }
}

int main() {
	int N; string cmd; int data;
	Linked ll;

	cin >> N;
	while (N--) {
		cin >> cmd;
		if (cmd == "addFront") {
			cin >> data;
			ll.addFront(data);
		}
		else if (cmd == "removeFront") {
			cout << ll.removeFront() << "\n";
		}
		else if (cmd == "front") {
			cout << ll.front() << "\n";
		}
		else if (cmd == "empty") {
			cout << ll.empty() << "\n";
		}
	}
}