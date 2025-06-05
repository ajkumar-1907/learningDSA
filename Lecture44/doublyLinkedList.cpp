#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }

    ~Node(){
        int val = data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "freed memory of node with data " << val << endl;
    }
};




// just print the list
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



// get length of list
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}



void insertAtHead(Node* &tail, Node* &head, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}




void insertAtTail(Node* &tail, Node* &head, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}




void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
    if(pos == 1){
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos - 1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, head, d);
        return;
    }

    Node* newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}





void deleteNode(int pos, Node* &head){
    if(pos == 1) {
        Node* temp = head;
        if(temp->next != NULL){
            temp->next->prev = NULL;
        }
        head = temp->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prevNode = NULL;
        int count = 1;

        while(count < pos){
            prevNode = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next != NULL){
            curr->next->prev = NULL;
        }

        prevNode->next = curr -> next;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}




int main() {

    Node* head = NULL;
    Node* tail = NULL;

    print(head);  // empty list

    insertAtHead(tail, head, 11);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;

    insertAtHead(tail, head, 13);
    print(head);

    insertAtHead(tail, head, 8);
    print(head);

    insertAtTail(tail, head, 25);
    print(head);

    insertAtPosition(tail, head, 2, 100);  // between 8 and 13
    print(head);

    insertAtPosition(tail, head, 1, 101);  // new head
    print(head);

    insertAtPosition(tail, head, 7, 102);  // at the end
    print(head);

    deleteNode(7, head);  // delete 102
    print(head);

    cout << "final head: " << head->data << ", final tail: " << tail->data << endl;

    return 0;
}
