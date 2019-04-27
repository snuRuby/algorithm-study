/*
*   하나 빼기
*/  

#include <iostream>
#include <string>

using namespace std;

bool isOne(string input1, string input2) {
    int count = 0;
    int whoislong = 0;
    //cout << "input1 length : " << input1.length() << endl;
    //cout << "input2 length : " << input2.length() << endl;

    if((((int)input1.length() - (int)input2.length()) > 1) || (((int)input1.length() - (int)input2.length()) < -1)) {
        return false;
    }

    // 길이가 같은 경우, 하나만 다른지 비교 - O(N)
    if(input1.length() == input2.length()){

        for(int i = 0; i < input1.length() ; ++i) {
            if(input1[i] != input2[i])
                count++;
        }

        if(count > 1)
            return false;
        
        return true;
    }
    // 길이가 1 다른 경우, iterator 이용
    whoislong = input1.length() > input2.length() ? 1 : 2;

    string::iterator iter1 = input1.begin();
    string::iterator iter2 = input2.begin();

    while(iter1 != input1.end() && iter2 != input2.end()) {
        if(*iter1 != *iter2) {
            //cout << "different!" << endl;
            if(whoislong == 1)
                iter1++;
            else
                iter2++;
        }
        else {
            //cout << "same!" << endl;
            iter1++;
            iter2++;
        }
    }

    if(iter1 == input1.end() && iter2 == input2.end())
        return true;
    if (whoislong == 1){
        if(++iter1 == input1.end() && iter2 == input2.end())
            return true;
        else
            return false;
    }
    if (whoislong == 2){
        if(iter1 == input1.end() && ++iter2 == input2.end())
            return true;
        else
            return false;
    }
    else
        return false;
    
}

int main() {
    string input1, input2;

    cin >> input1 >> input2;

    cout << isOne(input1, input2) << endl;

    return 0;
}