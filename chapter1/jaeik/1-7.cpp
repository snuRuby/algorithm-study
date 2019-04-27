#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int** a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				cout << a[i][j] << endl;
			}
			else
				cout << a[i][j] << ' ';
		}
	}

	cout << endl;

	int** b = new int*[n];
	for (int i = 0; i < n; i++) {
		b[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[j][n - i-1] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				cout << b[i][j] << endl;
			}
			else
				cout << b[i][j] << ' ';
		}
	}

	for (int i = 0; i < n; i++) {
		delete a[i];
		delete b[i];
	}
	delete a;
	delete b;
}