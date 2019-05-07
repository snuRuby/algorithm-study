#include <iostream>
#include <list>

using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }

    void insert(int data){
        Node* temp = this;
        Node* add = new Node(data);
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = add;
    }
};
void deleteNode(Node* unsorted){
    Node* temp1 = unsorted; Node* temp2 = unsorted;
    Node* dup;
    while(temp1 != NULL && temp1 -> next != NULL){
        temp2 = temp1;
        while(temp2 -> next != NULL) {
            if(temp1 -> data == temp2 -> next -> data){
                dup = temp2 -> next;
                temp2 -> next = temp2 -> next -> next;
                delete(dup);
            } else {temp2 = temp2 -> next;}
        }
        temp1 = temp1 -> next;
    }
}
int countOfList(Node* data);

int main(){
    srand(134510);
    int first = rand()%100;

    Node *new_data = new Node(first);
    for(int i = 0; i < first; i++){
        int input = rand()%10;
        new_data -> insert(input);
    }
    cout << "난수 리스트배열이 만들어 졌습니다."<< endl;
    cout << "난수 리스트 배열의 크기는 "<< to_string(first) << "입니다."<<endl;

    deleteNode(new_data);
    cout << "중복 리스트를 제거했습니다." << endl;
    cout << "현재 난수 리스트 배열의 크기는 "<< to_string(countOfList(new_data)) << "입니다." << endl;

    return 0;
}

int countOfList(Node* data){
    int count = 0;
    Node* slow_one = data;
    while(slow_one -> next != NULL){
        slow_one = slow_one -> next;
        count++;
    }
    return count;
}