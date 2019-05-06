#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Node{
    char data;
    struct Node *next;
    struct Node *prev;
    
    Node(char data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }

    void Insert(char data){
        Node *add = new Node(data);
        Node *temp = this;
        while(temp->next != NULL){
            temp = temp -> next;
        }
        temp -> next = add;
        add -> prev = temp;
    }
};
bool checkListPalindrome(Node* string);
Node* middleOfList(Node*string);

int main(){
    cout << "문자열을 입력해 주세요." << endl;
    char input[30];
    cin.getline(input, 30);
    Node *new_string = new Node(input[0]);
    for(int i = 1; i<=strlen(input) ; i++ ){
        new_string -> Insert(input[i]);
    }
    Node *temp = new_string;
    while(temp -> next != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
    bool isPalindrome = checkListPalindrome(new_string);
    if(isPalindrome){
        cout << "This word is palindrome";
    } else {cout<< "This word is not palindrome";}
    
}

bool checkListPalindrome(Node* string){
    Node *compare_point = middleOfList(string);
    Node *moving_point = middleOfList(string);

    while(moving_point->next != NULL){
        if(compare_point->prev == moving_point -> next){
            compare_point = compare_point -> prev;
            moving_point = moving_point -> next;
        } else {return false;}
    }
    return true;
}

Node* middleOfList(Node* string){
    Node* fast_one = string;
    Node* slow_one = string;
    if(fast_one != NULL && fast_one -> next != NULL){
        fast_one = fast_one -> next -> next;
        slow_one = slow_one -> next;
    }
    return slow_one;
}