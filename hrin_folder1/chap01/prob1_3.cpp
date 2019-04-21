//문자열 공백 %20으로 변경하는 문제
//https://m.blog.naver.com/cache798/130033385486 동적 메모리 할당 개념 잡기
//https://boycoding.tistory.com/205 동적으로 문자열 배열 할당하기 
// https://slowlywalk1993.tistory.com/entry/C-배열과-객체의-동적-할당 [천천히 걷는 방법]

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int countNumZero(char *str) {
    int count;

    for (int i=0; i<int(sizeof(str)); i++){
        if(str[i]==' '){count++;}
    }
    return count;
}

string changeStringToURL(int length, int count, char *str) {
    int new_length = 0;
    char *char_arr = new char[length + 2*count];
    for (int i = 0; i<length; i++) {
        if (str[i]==' '){
            char_arr[new_length] = '%';
            char_arr[new_length+1] = '2';
            char_arr[new_length+2] = '0';
            new_length += 2;
        }else {
            char_arr[new_length] = str[i];
            new_length++;
            }
    }
    string changed_string = char_arr;
    return changed_string;
}

int main() {
    cout << "문자열을 입력해 주세요";
    string input_string;
    cin >> input_string;
    
    int length = sizeof(input_string);
    
    char *char_array = new char[length];
    strcpy(char_array, input_string);
    if(!char_array) cout<<"메모리를 할당할 수 없습니다.";

    int null_number = countNumZero(char_array);
    string final_string = changeStringToURL(length, null_number, char_array);
    cout << "변환된 문자열은 " << final_string;

    delete[] char_array;

    return 0;
}
