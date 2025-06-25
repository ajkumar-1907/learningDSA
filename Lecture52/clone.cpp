#include <iostream>
using namespace std;

// Definition of Node including the 'arb' pointer
struct Node {
    int data;
    Node* next;
    Node* arb;

    Node(int val) {
        data = val;
        next = NULL;
        arb = NULL;
    }
};

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Create clone list nodes and insert between original nodes
        Node* temp = head;
        while (temp != NULL) {
            Node* cloneNode = new Node(temp->data);
            cloneNode->next = temp->next;
            temp->next = cloneNode;
            temp = cloneNode->next;
        }

        // Step 2: Copy arb pointers
        temp = head;
        while (temp != NULL) {
            if (temp->arb != NULL) {
                temp->next->arb = temp->arb->next;
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the original and cloned list
        Node* original = head;
        Node* cloneHead = head->next;
        Node* copy = cloneHead;

        while (original != NULL) {
            original->next = original->next ? original->next->next : NULL;
            copy->next = copy->next ? copy->next->next : NULL;
            original = original->next;
            copy = copy->next;
        }

        return cloneHead;
    }
};


void printClonedList(Node* head) {
    while (head) {
        cout << "Data: " << head->data << ", Random: ";
        if (head->arb)
            cout << head->arb->data << endl;
        else
            cout << "NULL" << endl;
        head = head->next;
    }
}

int main() {
    // Creating a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Setting up arb pointers
    head->arb = head->next->next;       // 1 -> 3
    head->next->arb = head;             // 2 -> 1
    head->next->next->arb = head->next->next->next; // 3 -> 4
    head->next->next->next->arb = head->next;       // 4 -> 2

    Solution sol;
    Node* clonedList = sol.copyList(head);

    cout << "Original List:\n";
    printClonedList(head);

    cout << "\nCloned List:\n";
    printClonedList(clonedList);

    return 0;
}
