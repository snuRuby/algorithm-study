#include <iostream>
#include <string.h>
using namespace std;

bool is_Substring(string input1, string input2){
    int size1=input1.length();
    int size2=input2.length();
    if(size1>=size2)
    {
        if(input1.find(input2)<size1) return true;
    }
    else
    {
        if(input2.find(input1)<size2) return true;
    }
    return false;
}

bool is_Rotate(string input1, string input2){
    if(input1.length()!=input2.length()) return false;
    input2+=input2;
    return is_Substring(input1, input2);
}

int main()
{
    string input1, input2;
    cin>>input1>>input2;
    cout<<is_Rotate(input1, input2)<<endl;
}