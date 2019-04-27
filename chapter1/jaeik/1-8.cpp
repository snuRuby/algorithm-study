#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand()%10;
		}
	}
	a[1][2] = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				cout << a[i][j] << endl;
			}
			else
				cout << a[i][j] << ' ';
		}
	}

	cout << endl;
	vector<int> v_row,v_col;

 	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				v_row.push_back(i);
				v_col.push_back(j);
			}
		}
	}

	for (int i = 0; i < v_row.size(); i++) {
		for (int j = 0; j < n; j++) {
			a[v_row[i]][j] = 0;
		}
	}

	for (int i = 0; i < v_col.size(); i++) {
		for (int j = 0; j < m; j++) {
			a[j][v_col[i]] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) {
				cout << a[i][j] << endl;
			}
			else
			cout << a[i][j] << ' ';
		}
	}

	for (int i = 0; i < m; i++) {
		delete a[i];
	}
	delete a;
}