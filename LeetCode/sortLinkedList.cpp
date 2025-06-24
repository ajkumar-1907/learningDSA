#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

    ~Node(){
        cout<< " Deleting Node with Data : "<<data<<endl;
    }
};


Node* uniqueSortedList(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) && (curr -> data == curr -> next -> data)){
            Node* next_next = curr -> next -> next;
            delete curr -> next;
            curr -> next = next_next;
        }else{
            curr = curr -> next;
        }
    }

    return head;
}



void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* head = NULL;

    // Example input: sorted list with duplicates
    insertAtTail(head, 1);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    cout << "Original list: ";
    printList(head);

    head = uniqueSortedList(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}