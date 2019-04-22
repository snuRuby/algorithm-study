#include "iostream"
#include <string.h>
using namespace std;


bool RepeatChk_1(char arrayt[], int strlength) {
	int chararray[95] = { 0 };                                    
	
	for (int i = 0; i < strlength; ++i) {
		chararray[arrayt[i] - 32] += 1;                            
	}
	
	for (int j = 0; j < 95; ++j) {
		if (chararray[j] > 1) {                                    
			cout << "중복된 문자가 존재합니다." << endl;
			return 1;                                              
		}
	}
	
	cout << "중복된 문자가 존재하지 않습니다." << endl;             
	return 0;                                                      
}


bool RepeatChk_2(char arrayt[], int strlength ) {

	for (int i = 0; i < strlength; ++i) {
		for (int j = 1; j < strlength - i; ++j) {
				if (arrayt[i] == arrayt[i + j]) {
				cout << "중복된 문자가 존재합니다." << endl;
				return 1;
			}
		}
	}

	cout << "중복된 문자가 존재하지 않습니다." << endl;             
	return 0;                                                      
}


bool RepeatChk(char arrayt[]) {
	int strlength = strlen(arrayt);
	
	if (strlength > 11)
		return RepeatChk_1(arrayt,strlength);
	else
		return RepeatChk_2(arrayt,strlength);
                                             
}



int main() {
	char a[10] = { 0 };
	int exit = 0;
	
	while(1){
	cout << "확인할 문자열을 적으시오." << endl;
	cin >> a;
	RepeatChk(a);
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	}

	return 0;
}