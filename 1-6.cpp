#include <iostream>
#include <string.h>
using namespace std;


string Compress(string input)
{
    input+='0';
    string Compressed_input="";
    int num=1;
    for(int i=0; i<input.length()-1; i++){
       if(input[i]==input[i+1]){
           num++;
       }
       else if(input[i]!=input[i+1]){
            Compressed_input+=input[i-num+1];
            Compressed_input+=to_string(num);
            num=1;
       }
    }
    return Compressed_input;
}

int main()
{
    string input;
    cin>>input;
    string input2 = Compress(input);
    if(input2.length()>input.length()) cout<<input<<endl;
    else cout<<input2<<endl;
}