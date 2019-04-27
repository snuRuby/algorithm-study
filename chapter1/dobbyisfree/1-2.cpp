#include "iostream"
#include <string.h>
using namespace std;


bool Permut_1(char a[], char b[]) {
	int a_length = strlen(a);
	int b_length = strlen(b);
	int a_existAlp[95] = { 0 };                                
	int b_existAlp[95] = { 0 };                                  
	
	if (a_length != b_length) {
		cout << "두 문자열은 순열관계가 아닙니다." << endl;
		return 0;
	}

	for (int i = 0; i < a_length; ++i) {
		a_existAlp[a[i]-32] += 1;
		b_existAlp[b[i]-32] += 1;                           
	}
	
	for(int k=0; k<95; ++k){
		if (a_existAlp[k] != b_existAlp[k]) {
			cout << "두 문자열은 순열관계가 아닙니다." << endl;
			return 0;
		}
	}
	cout << "두 문자는 순열관계입니다." << endl;
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
		Permut_1(a,b);
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	}

	return 0;
}
