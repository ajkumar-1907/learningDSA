#include<iostream>

using namespace std;


class Node{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};





Node* floydDetectLoop(Node* head){
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}





// Get starting node of the loop
Node* getStartingNode(Node* head){
    if (head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);
    if (intersection == NULL)
        return NULL;

    Node* slow = head;
    while (slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}




// Remove the loop in the linked list
Node* removeLoop(Node* head){
    if(head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop;
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}






void insertAtTail(Node* &head, int data){
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


void createLoop(Node* &head, int pos) {
    if (pos == -1) return;

    Node* loopStart = head;
    for (int i = 1; i < pos; i++) {
        loopStart = loopStart->next;
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = loopStart;
}


int main() {
    Node* head = NULL;

    int n, data, pos;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }

    cout << "Enter position to create loop (-1 for no loop): ";
    cin >> pos;

    createLoop(head, pos);

    if (floydDetectLoop(head) != NULL) {
        cout << "Loop detected. Removing loop...\n";
        head = removeLoop(head);
    } else {
        cout << "No loop found.\n";
    }

    cout << "Linked List after loop removal: ";
    printList(head);

    return 0;
}
