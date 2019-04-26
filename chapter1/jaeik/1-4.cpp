#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int	hash[26];
	for (int i = 0; i < 26; i++) {
		hash[i] = 0;
	}

	for (int i = 0; i < s.size(); i++) {
		hash[(s.at(i)) % 32-1]++;
	}

	int count = 0;

	for (int i = 0; i < 26; i++) {
		if (hash[i] % 2 == 1)
			count++;
	}

	if (count == 0 || count == 1) {
		cout << "True" << endl;
	}
	else
		cout << "False" << endl;
}