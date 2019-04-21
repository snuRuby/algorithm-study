#include <iostream>
#include <string.h>
using namespace std;


bool is_one(string input1, string input2)
{
    int size1, size2;
    size1= input1.length(); size2= input2.length();
    int check1=0; //다른 문자 개수
    if(size1-size2>1 || size1-size2<-1) return false;  //두 문자열의 길이가 2이상 차이나면 false

 // 두 문자열의 길이가 같은 경우   
    else if(size1==size2){ 
        for(int i=0; i<input1.length(); i++)
        {
            if(int(input1[i])!=int(input2[i])) check1++; // 문자가 다를 때마다 증가
            if(check1==2) return false; // 2개 이상 문자가 다르면 false
        } 
        return true; //문자가 1개만 서로 다르거나 일치하는 경우
    }

//두 문자열의 길이가 1 차이 나는 경우
    else{           
        string input3, input4;
        int size;
        //더 긴 문자열을 input3에 복사, 더 긴 문자열의 길이를 size에 복사
        if(size1>size2) {
            input3=input1;
            input4=input2;
            size= size1;
        }
        else{
            input3 = input2;
            input4 = input1;
            size=size2;
        }

        int check2=0; //다른 문자 개수
        //더 긴 문자열에서 각 문자를 한번씩 빼보고 비교
        for(int i=0; i<size; i++){
            for(int j=0; j<size-1; j++){
                if(j<i){
                   if(int(input3[j])!=int(input4[j])){
                       check2++;
                       break;
                   }
               }
               if(j>=i){
                   if(int(input3[j+1])!=int(input4[j])){
                       check2++;
                       break;
                   }
               }
            }
        }
        if(check2<size) return true; //한번이라도 일치하는 경우가 있다면 True
        else return false;
    }

}

int main()
{
    string input1, input2;
    cin>>input1>>input2;
    if(is_one(input1, input2)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}