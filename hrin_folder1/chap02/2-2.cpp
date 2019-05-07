#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct Node{
    int data;
    struct Node* next;

    Node(int data){
        this ->data = data;
        next = NULL;
    }
    void insert(int data){
        Node *temp = this;
        Node *add = new Node(data);
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = add;
    }
};

int middleOfList(Node* data);
Node* nodeKFromBack(int k, int count, Node* start);

int main(){
    srand(134510);
    int first = rand()%100;

    Node *new_data = new Node(first);
    for(int i = 0; i < first; i++){
        int input = rand();
        new_data -> insert(input);
    }
    cout << "난수 리스트배열이 만들어 졌습니다."<< endl;
    cout << "K를 정해주세요" << endl;

    int k;
    cin >> k;
    if(!cin){
        cout << "숫자만 입력하세요" << endl;
        cin.clear();
        cin.ignore(__INT_MAX__,'\n');
    }
    int half = middleOfList(new_data);
    Node *node_K = nodeKFromBack(k, half, new_data);
    cout << "뒤에서 K번째는 " << node_K->data << "입니다. "<< endl;

    cout << "확인해봅시다. "<< endl;

    Node *temp = new_data;
    for(int i = 0; i< first - k; i++){
        temp = temp -> next;
    }
    cout << temp -> data;

    if(temp->data == node_K -> data){
        cout << "correct!";
    } else {cout << "fail!";}
    return 0;
}

int middleOfList(Node* data){
    int count = 0;
    Node* fast_one = data;
    Node* slow_one = data;
    while(fast_one != NULL && fast_one -> next != NULL){
        fast_one = fast_one -> next -> next;
        slow_one = slow_one -> next;
        count++;
    }
    return count;
}

Node* nodeKFromBack(int k, int count, Node* start){
    Node *temp = start;
    for(int i=0; i<2*count -k ; i++){
        temp = temp -> next;
    }
    return temp;
}

