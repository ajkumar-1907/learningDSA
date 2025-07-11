#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* solve(Node* first, Node* second){


    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)){
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else{
            curr1 = next1;
            next1 = next1 ->next;

            if (next1 == NULL){
                curr1->  next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second){
    if (first == NULL){ 
    return second;
    }
    
    if(second == NULL){ 
        return first;
    }

    if (first  ->data <= second -> data){
        return solve(first, second);
    }else{
        return solve(second, first);
    }
}

void printList(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertTail(Node*& head, Node*& tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int main() {
    Node* first = NULL;
    Node* tail1 = NULL;
    insertTail(first, tail1, 1);
    insertTail(first, tail1, 3);
    insertTail(first, tail1, 5);

    Node* second = NULL;
    Node* tail2 = NULL;
    insertTail(second, tail2, 2);
    insertTail(second, tail2, 4);
    insertTail(second, tail2, 6);

    Node* merged = sortTwoLists(first, second);
    printList(merged);

    return 0;
}
