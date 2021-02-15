#include<iostream>
using namespace std;

int arr[10000];

int at(int idx) {
	if (idx > 10000) { return -1; }
	else {
		return arr[idx];
	}
}

void set(int idx, int data) {
	if (arr[idx] == 0) { cout << "0\n"; return; }
	else { arr[idx] = data; return; }

}

void add(int idx, int data) {
	int arr_size = 0;

	for (int i = 0; i < 10000; i++) {
		if (arr[i] == 0) { arr_size = i; break; }
	}

	if (arr_size == 0) { arr[0] = data; return; }
	else if (arr[idx] == 0) { arr[arr_size] = data; return; }
	else {
		for (int i = arr_size; i > idx; i--) {
			arr[i] = arr[i - 1];
		}
		arr[idx] = data;
		return;
	}
}

int main() {
	int n, idx, data;
	string cmd;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "at") {
			cin >> idx;
			cout << at(idx) << "\n";
		}
		else if (cmd == "set") {
			cin >> idx >> data;
			set(idx, data);
		}
		else {
			cin >> idx >> data;
			add(idx, data);
		}
	}
}