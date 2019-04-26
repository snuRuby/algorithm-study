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
			cout << "회문순열이 아닙니다." << endl;
			return 0;
			}
		}
	}

	cout << "회문순열입니다" << endl;             
	return 1;                                                      
}

int main() {
	char a[20] = { 0 };
	int exit = 0;

	while (1) {
		cout << "확인할 문자열을 적으시오." << endl;
		cin >> a;
		RepeatChk(a, 20);
		cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	}

	return 0;
}