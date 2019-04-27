/*
*   make URL
*/

#include <iostream>
#include <string>

using namespace std;

string makeURL(string input) {
    int count = 0;
    int index = 0;
    char * URL;

    for(int i = 0 ; i < input.length() ; ++i) {
        if(input[i] == ' ')
            count += 1;
    }

    URL = new char[input.length() + count * 2];

    for(int i = 0; i < input.length() ; ++i) {
        if(input[i] == ' ') {
            URL[index++] = '%';
            URL[index++] = '2';
            URL[index++] = '0';
        }
        else {
            URL[index++] = input[i];
        }
    }

    return URL;
    
}

int main() {
    string input;

    getline(cin, input);

    cout << makeURL(input) << endl;
}
