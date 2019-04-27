#include <iostream>
#include <list>

using namespace std;

int findFromBack(list<int>& input, int index){
    list<int>::iterator iter1, iter2;
    iter1 = input.begin();
    iter2 = input.begin();

    for(int i = 0; i<index;++i){
        iter2++;
    }

    while(iter2 != input.end()){
        iter1++;
        iter2++;
    }

    return *iter1;
}

int main() {
    int list_length;
    int list_input;
    int index;
    list<int> input;

    cin >> list_length;

    for(int i = 0; i < list_length ; ++i) {
        cin >> list_input;
        input.push_back(list_input);
    }

    cin >> index;

    cout << findFromBack(input, index) << endl;

    return 0;

}

