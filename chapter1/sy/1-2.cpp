/*
*   Check Permutation
*/

#include <iostream>
#include <string>

using namespace std;


bool checkPer(string input1, string input2) {
    char temp1[input1.length()];
    char temp2[input2.length()];

    if(input1.length() != input2.length())
        return false;

    for(int i=0 ; i < input1.length() ; ++i) {
        temp1[i] = input1[i];
    }

    for(int i=0 ; i < input2.length() ; ++i) {
        temp2[i] = input2[i];
    }
    sort(temp1, temp1+input1.length());
    sort(temp2, temp2+input2.length());

    for(int i=0 ; i < input1.length() ; ++i) {
        if(temp1[i] != temp2[i])
            return false;
    }
    
    return true;
}

int main() {
    string input1, input2;

    cin >> input1 >> input2;

    cout << checkPer(input1, input2) << endl;
}
