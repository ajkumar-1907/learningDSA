//Solution with data replacement
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};



Node* sortList(Node* head){
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            zeroCount++;
        }else if(temp -> data == 1){
            oneCount++;
        }else if(temp -> data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;
    while(temp != NULL){
        if(zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        } else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        } else if(twoCount != 0){
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }

    return head;
}





void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}




void insertTail(Node*& head, Node*& tail, int data){
    Node* newNode = new Node(data);
    if (head == NULL){
        head = newNode;
        tail = newNode;
    } else{
        tail-> next = newNode;
        tail = newNode;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertTail(head, tail, 2);
    insertTail(head, tail, 1);
    insertTail(head, tail, 0);
    insertTail(head, tail, 1);
    insertTail(head, tail, 2);
    insertTail(head, tail, 0);
    insertTail(head, tail, 1);

    printList(head);

    head = sortList(head);

    printList(head);

    return 0;
}
