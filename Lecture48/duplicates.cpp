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

Node* uniqueSortedList(Node* head){
    if (head == NULL)
        return NULL;

    Node* curr = head;

    while (curr != NULL){
        if (curr->next != NULL && curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        } else{
            curr = curr->next;
        }
    }

    return head;
}

void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if (head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> val;
        insertAtTail(head, val);
    }

    head = uniqueSortedList(head);
    printList(head);

    return 0;
}
