//Solution without data replacement
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


void insertAtTail(Node*& tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}


Node* sortList(Node* head){

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while(curr != NULL){
        int value = curr->data;

        if(value == 0){
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1){
            insertAtTail(oneTail, curr);
        }
        else if(value == 2){
            insertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    } else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;



    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

void printList(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertTail(head, tail, 1);
    insertTail(head, tail, 0);
    insertTail(head, tail, 2);
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 0);
    insertTail(head, tail, 1);

    printList(head);

    head = sortList(head);

    printList(head);

    return 0;
}
