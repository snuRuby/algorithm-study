#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
   friend class List;      // List클래스는 Node클래스의 private에 접근할 수 있음
private:
   int     value;      // 밸류 저장용
   Node   *next;      // Node를 가르킬 수 있는 포인터(화살표)
   Node(int v, Node *n) : value(v), next(n) { }
};

class List
{
private:
   Node *head;    // 리스트의 첫 노드를 가르킴
   Node *tail;      // 리스트의 마지막 노드를 가르킴
   int size;      // 노드의 갯수
public:
   List(int);            //생성자
   void pushBack(int);      //리스트의 맨 마지막에 노드를 삽입
   void popFront();      //리스트의 맨 처음 노드를 제거
   void insert(int);      //리스트의 중간에 노드를 삽입 (value의 크기 순서대로 삽입한다)
   void Overlap();
   void print();         //리스트의 내용물을 출력한다
   ~List();            //소멸자
};
List:: List(int v)      // 노드가 하나인 리스트를 생성
{
   head = tail = new Node(v, NULL);
   size = 1;      // 사이즈가 1이다 (노드 1개)
}
void List::pushBack(int value)      //리스트의 맨 마지막에 노드를 삽입
{
   Node *newNode = new Node(value, NULL); // 삽입할 노드 생성
   if (head == NULL)      // 리스트가 비었다면
      head = newNode;      //    삽입할 노드가 첫 노드가 된다.
   else
      tail->next = newNode;   // 리스트에 원소가 하나이상 존재한다면 현재의 마지막 노드의 다음을 삽입할 노드로 설정한다.
   tail = newNode;      // 리스트가 비었든지 말든지 삽입할 노드는 노드의 마지막.
   size++;         //사이즈 1 증가.
}
void List::popFront()      //리스트의 맨 처음 노드를 제거
{
   if (head != NULL)      // 리스트에 노드가 최소 하나 존재해야지 제거가 가능
   {
      Node *removal = head;   // 제거될 노드의 정보를 담을 임시노드 생성 (swap 구현할때 temp 변수와 같은 용도)
      head = head->next;   // 두번째 노드가 첫 노드가 된다.
      delete removal;      // 첫째 노드 제거
      size--;         // 사이즈 1 감소
   }
}
void List::insert(int value)      //리스트의 중간에 노드를 삽입 (value의 크기 순서대로 삽입한다)
{
   Node *insert = new Node(value, NULL);
   Node *scan; //탐색용 임시노드
   if (head != NULL) //리스트에 원소가 최소 한개 있다면 (비어있지 않다면)
   {
      if (head->value > value) {      //삽입할 노드가 리스트의 첫 노드보다 작은경우 (pushFront)
         insert->next = head;
         head = insert;
      }
      else if (tail->value < value) {      //삽입할 노드가 리스트의 마지막노드보다 큰 경우 (pushBack)
         tail->next = insert;
         tail = insert;
      }
      else {      //그 외의 경우
         scan = head;
         while (scan->next->value < insert->value) // 노드가 삽입될 위치를 찾때까지 scan을 진행한다.
            scan = scan->next;
         insert->next = scan->next;  //포인터(화살표) 수정
         scan->next = insert;   //포인터(화살표)수정 2
      }
   }
   else //리스트가 비었다면 그냥 삽입
   {
      head = insert;
      tail = insert;
      head->next = NULL;
   }
   size++; //사이즈 1 증가
}

void List::Overlap(){
    Node *scan1 =head;
    Node *scan2 =head->next;
    while(scan1 != NULL){
        while(scan2 != NULL){
            if(scan1->value == scan2->value){
                if(scan2->next!=NULL){
                    scan2->value=scan2->next->value;
                    scan2->next=scan2->next->next;
                    size--;
                   delete scan2->next;
                }
                else{
                    delete scan2;
                }
            }
            else{
                scan2=scan2->next;
            }
        }
        scan1=scan1->next;
        if(scan1==NULL){
            scan2=NULL;
        }
        else{
            scan2=scan1->next;
        }
    }
}


void List::print()
{
   Node *scan = head;
   while (scan != NULL)
   {
      cout << scan->value << endl;
      scan = scan->next;
   }
}
List::~List()         // 소멸자
{
   while (head != NULL)
      popFront();      
}



int main()
{
   List a(3);
   a.pushBack(5);
   a.pushBack(8);
   a.pushBack(5);
   a.pushBack(10);
   a.Overlap();
   a.print();
}