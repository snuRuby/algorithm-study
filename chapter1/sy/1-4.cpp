#include <iostream>
#include <string>

using namespace std;

bool checkPalinPer(string input) {
    char temp[input.length()];
    int odd = 0;
    int index = 0;
    int count = 1;
    for (int i = 0 ; i < input.length() ; ++i)
        temp[i] = input[i];
    //Sorting, O(NlogN)
    sort(temp, temp+input.length());

    while(index < input.length()-1) {
        if(temp[index] == temp[index+1])
            count++;
        else {
            if(count % 2 != 0)
                odd += 1;
            count = 1;
        }
        index++;
    }

    if(count % 2 !=  0)
        odd += 1;

    if(odd <= 1)
        return true;
    else
        return false;
    

}

int main() {
    string input;

    cin >> input;

    cout << checkPalinPer(input) << endl;
    
    return 0;
}