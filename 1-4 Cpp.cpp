#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


bool is_palindrome(string input)
{
    unsigned int check_num[36]={0};
    for(int i=0; i<input.length(); i++){
        if(int(input[i])<91&&int(input[i])>64) check_num[int(input[i])-65]++;
        else if(int(input[i])>96&&int(input[i])<123) check_num[int(input[i])-97]++;
        else if(int(input[i])>47&&int(input[i])<58) check_num[int(input[i])-23]++;
    }
    int odd=0;
    for(int i=0; i<26; i++)
    {
        if(check_num[i]%2 == 1) odd++;
        if(odd==2) return false;
    }
    return true;
    
}

int main()
{
    string input;
    getline(cin,input);
    if(is_palindrome(input)) cout<<"True";
    else cout<<"False";
}