#include <iostream>
#include <string>

using namespace std;

/*
*   check Duplicate, O(n^2) time complexity
*/
bool checkDup(string str) {
    for(int i=0;i<str.length();++i) {
        for(int j =i+1;j<str.length();++j){
            if(str[i] == str[j])
                return true;
        }
    }
    return false;
}

/*
*   check Duplicate, O(nlogn) time complexity
*/
bool checkDupFast(string str) {
    char temp[str.length()];
    for(int i = 0; i < str.length() ; ++i) {
        temp[i] = str[i];
    }
    // Sorting : O(NlogN)
    sort(temp, temp+str.length());
    // Check
    for(int i = 0 ; i < str.length()-1 ; ++i) {
        if(temp[i] == temp[i+1])
            return true;
    }
    return false;
}

/*
*   main function for Chapter 1 Problem Set
*/
int main() {
    string str;

    cin >> str;
    cout<<"checkDup function"<<endl;
    cout<<checkDup(str)<<endl;
    
    cout<<"checkDupFast function"<<endl;
    cout<<checkDupFast(str)<<endl;
}


