/*
*   문자열 회전
*/

#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string input1, string input2) {
    return input1.find(input2) != string::npos;
}

bool isShift(string input1, string input2) {
    return isSubstring(input1.append(input1), input2);
}

int main() {
    string input1, input2;

    cin >> input1 >> input2;
    cout << isShift(input1, input2) << endl;

    return 0;
}