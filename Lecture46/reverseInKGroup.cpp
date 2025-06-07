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

// Function to reverse k nodes in linked list
Node* kReverse(Node* head, int k) {
    // base case
    if(head == NULL) {
        return NULL;
    }

    // reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }


    if(next != NULL) {
        head -> next = kReverse(next, k);
    }

    
    return prev;
}


void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}


int main() {
    Node* head = NULL;
    int n, k, val;

    cout << "Enter number of elements in the linked list: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Original List: ";
    printList(head);

    head = kReverse(head, k);

    cout << "Reversed in groups of k: ";
    printList(head);

    return 0;
}
