#include "iostream"
#include <string.h>
using namespace std;


bool Check(char a[], char b[]) {
	int a_length = strlen(a);
	int b_length = strlen(b);
	int a_cnt = 0;
	int b_cnt = 0;

	if (((a_length-b_length)>1)&&((a_length-b_length)<-1)) {
		cout << "�Ұ����մϴ�." << endl;
		return 0;
	}

	for (int i = 0; i < a_length; ++i) {
		if ((a[i+a_cnt] != b[i+b_cnt])) {
			if (a_cnt || b_cnt) {
				cout << "�Ұ����մϴ�" << endl;
				return 0;
			}
			else if ((a[i + a_cnt] == b[i + 1 + b_cnt])){
				b_cnt += 1;
			}
			else if ((a[i + a_cnt + 1] == b[i + b_cnt])) {
				a_cnt += 1;
			}
			else if ((a[i + 1 + a_cnt] == b[i + 1 + b_cnt])) {
				a_cnt += 1;
				b_cnt += 1;
			}
			else {
				cout << "�Ұ����մϴ�" << endl;
				return 0;
			}
		}
	}
	cout << "�����մϴ�" << endl;
	return 1;
}


int main() {
	char a[20] = { 0 };
	char b[20] = { 0 };


	while (1) {
		cout << "Ȯ���� ù��° ���ڿ��� �����ÿ�." << endl;
		cin >> a;
		cout << "Ȯ���� �ι�° ���ڿ��� �����ÿ�." << endl;
		cin >> b;
		Check(a, b);
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	}

	return 0;
}