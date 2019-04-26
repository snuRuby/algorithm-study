#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, s_c;
	cin >> s >> s_c;

	int count = 0;
	if ((s.length() - s_c.length()) > 1 || (s_c.length() - s.length()>1)) {
		cout << "False" << endl;
		return;
	}
	else {
		int i, j = 0;
		while (i < s.length() && j < s_c.length()) {
			if (count > 1) {
				cout << "False" << endl;
				return;
			}
			if (s.at(i) != s_c.at(j)) {
				if (s.at(i + 1) == s_c.at(j + 1))
				{
					i++;
					j++;
					count++;
				}
				else {
					if (s.length() > s_c.length()) {
						i++;
					}
					else if (s.length() < s_c.length()) {
						j++;
					}
					else {
						i++;
						j++;
					}
					count++;
				}
			}
			else {
				i++;
				j++;
			}
		}
		cout << "True" << endl;
		return;
	}
}