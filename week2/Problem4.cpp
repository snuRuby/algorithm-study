#include "iostream"
using namespace std;

class Node {
private:
	int value;
	Node* next;
	friend class List;
};

class List {
public:
	List();
	~List();
	void showallval();
	void addFront(int val);
	int getval(int index);
	void del();
	void division(int val);
	int findval(int val);
	void gotoFirst(int index);
private:
	Node* head;
	int size;

};

List::List() :head(NULL), size(0) {}

List::~List() {
	while (head != NULL) {
		del();
	}
}

void List::addFront(int val) {
	Node* v = new Node;
	v->value = val;
	v->next = head;
	head = v;
	size++;
}

void List::showallval() {
	Node* tmpptr = head;
	while (tmpptr != NULL) {
		cout << tmpptr->value << " ";
		tmpptr = tmpptr->next;
	}

}

int List::getval(int index) {
	Node* tmpptr = head;
	for (int i = 0; i < index; ++i) {
		tmpptr = tmpptr->next;
	}
	return (tmpptr->value);
}

void List::del() {
	Node* tmp = head;
	head = tmp->next;
	delete tmp;
	size++;
}

void List::gotoFirst(int index) {
	Node* tmpptr = head;
	Node* orig = new Node;
	for (int i = 0; i < index - 1; ++i) {
		tmpptr = tmpptr->next;
	}
	orig = tmpptr->next;
	tmpptr->next = tmpptr->next->next;
	orig->next = head;
	head = orig;

}

int List::findval(int val) {
	for (int i = 0; i < size; ++i) {
		if (getval(i) == val) return i;
	}
}


/////////////////////////링크드리스트 관리함수/////////////////////////////////////

void List::division(int val) {
	int value = 0;
	int valindex = findval(5);
	for (int i = 0; i < size; ++i) {
		value = getval(i);
		if (value < val && i>valindex) {
			gotoFirst(i);
		}
	}
}

int main() {
	List list;
	list.addFront(1);
	list.addFront(2);
	list.addFront(10);
	list.addFront(5);
	list.addFront(8);
	list.addFront(5);
	list.addFront(3);
	list.showallval();
	list.division(5);
	cout << endl;
	list.showallval();

	return 0;

}



