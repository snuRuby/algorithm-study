/*
*   문자열 압축
*/

#include <iostream>
#include <string>

using namespace std;

string stringCompress(string input) {
    if(input.length() == 1)
        return input;
    
    int count = 1;
    string output;
    
    // string& append (size_t n, char c);
    for(int i = 0 ; i < input.length() - 1 ; ++i) {
        if(input[i] != input[i+1]) {
            output.append(1, input[i]);
            output.append(to_string(count));
            count = 1;
        }
        else {
            count += 1;
        }
    }

    output.append(1, input[input.length()-1]);
    output.append(to_string(count));

    if(input.length() < output.length())
        return input;
    else
        return output;

}

int main() {
    string input;

    cin >> input;

    cout << stringCompress(input) << endl;

    return 0;
}