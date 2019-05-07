#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

struct Node {
    char data;
    struct *Node next;

    struct Node (char data){
        this -> data = data;
        next = NULL;
    }

    void insert(char data){
        Node *add = Node(data);
        Node *temp = this;
        while(temp -> next != NULL){
            temp = temp->next;
        }
        temp -> next = add;
    }
}

bool isLoop(Node *string);

int main() {
    cout << "문자열을 입력해 주세요." << endl;
    char input[30];
    cin.getline(input, 30);
    Node *new_string = new Node(input[0]);
    for(int i = 1; i<strlen(input) ; i++ ){
        new_string -> insert(input[i]);
    }

    srand(1234);
    random_int = rand()%(strlen(input)-1)
    Node *temp = new_string;
    for(int i=0; i<random_int; i++){
        temp = temp -> next;
    }
    
    Node *temp2 = new_string;
    while(temp2 -> next != NULL) {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp;
    cout << random_int << "번째 포인트부터 회전하기 시작합니다." << endl;



    return 0;
}

int isLoop(Node *string){
    if(string == NULL){
        return -1;
    }
    Node *temp = string;
    
}