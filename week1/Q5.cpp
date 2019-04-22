#include "iostream"
#include <string.h>
using namespace std;


bool Check(char a[], char b[]) {
	int a_length = strlen(a);
	int b_length = strlen(b);
	int a_cnt = 0;
	int b_cnt = 0;

	if (((a_length-b_length)>1)&&((a_length-b_length)<-1)) {
		cout << "불가능합니다." << endl;
		return 0;
	}

	for (int i = 0; i < a_length; ++i) {
		if ((a[i+a_cnt] != b[i+b_cnt])) {
			if (a_cnt || b_cnt) {
				cout << "불가능합니다" << endl;
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
				cout << "불가능합니다" << endl;
				return 0;
			}
		}
	}
	cout << "가능합니다" << endl;
	return 1;
}


int main() {
	char a[20] = { 0 };
	char b[20] = { 0 };


	while (1) {
		cout << "확인할 첫번째 문자열을 적으시오." << endl;
		cin >> a;
		cout << "확인할 두번째 문자열을 적으시오." << endl;
		cin >> b;
		Check(a, b);
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	}

	return 0;
}