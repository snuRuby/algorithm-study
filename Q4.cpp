#include "iostream"
using namespace std;

bool RepeatChk(char arrayt[], int strlength) {
	int chararray[95] = { 0 };                                   
	int oddcnt=1;

	for (int i = 0; i < strlength; ++i) {
		chararray[arrayt[i] - 32] += 1;                            
	}

	for (int j = 0; j < 95; ++j) {
		if (((chararray[j] %2) == 1)) {                                    
			if (oddcnt == 1) {
			oddcnt -= 1;
			}
			else {
			cout << "ȸ�������� �ƴմϴ�." << endl;
			return 0;
			}
		}
	}

	cout << "ȸ�������Դϴ�" << endl;             
	return 1;                                                      
}

int main() {
	char a[20] = { 0 };
	int exit = 0;

	while (1) {
		cout << "Ȯ���� ���ڿ��� �����ÿ�." << endl;
		cin >> a;
		RepeatChk(a, 20);
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	}

	return 0;
}