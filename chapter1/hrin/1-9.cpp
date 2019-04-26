#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) {
            if (s2[i + j] != s1[j]) {
                break;
            }
        }
  
        if (j == M) {return i;}
    } 
  
    return -1; 
} 
/*https://www.geeksforgeeks.org/check-string-substring-another/ */

bool isRotated(string str1, string str2) {
    int str1_len = str1.length();
    int str2_len = str2.length();
    if(str1_len == str2_len and str1_len>0){
        string concat_str1 = str1 + str1;
        int count = isSubstring(concat_str1, str2);
        if (count == -1) {return false;} else {return true;}
    } else {return false;}
}
int main() {
    string str1 = "Rubyisfine";
    string str2 = "fineRubyis";
    bool boolean = isRotated(str1, str2);
    if (boolean) {cout<< "String 2 was rotated!"<<endl;} else {cout<<"String 2 was not rotated!"<<endl;}
    return 0;
}

