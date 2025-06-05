#include<iostream>
#include<map>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Deleted node with data " << val << endl;
    }
};


void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}




void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}



void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}







void insertAtPosition(Node* &tail, Node* &head, int pos, int d){
    if(pos == 1){
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node * newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}




void deleteNode(int position, Node* &head){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}




bool isCircularList(Node* head){
    if(head == NULL) return true;

    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    return temp == head;
}




bool detectLoop(Node* head){
    if(head == NULL) return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){
        if(visited[temp] == true) {
            cout << "Loop found at node: " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}



Node* floydDetectLoop(Node* head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout << "Loop detected at: " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}





Node* getStartingNode(Node* head){
    if(head == NULL) return NULL;

    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL) return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}






void removeLoop(Node* head){
    if(head == NULL) return;

    Node* startLoop = getStartingNode(head);
    if(startLoop == NULL) return;

    Node* temp = startLoop;

    while(temp->next != startLoop){
        temp = temp->next;
    }

    temp->next = NULL;
}




int main() {

    Node * node1 = new Node(10);
    
    Node * head = node1;
    Node * tail = node1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtPosition(tail, head, 4, 22);

    // create a loop
    tail->next = head->next;

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    if(floydDetectLoop(head) != NULL){
        cout << "Cycle is present" << endl;
    } else {
        cout << "No cycle found" << endl;
    }

    Node* loopStart = getStartingNode(head);
    if(loopStart != NULL)
        cout << "Loop starts at node with data: " << loopStart->data << endl;

    removeLoop(head);
    cout << "After removing loop: ";
    print(head);




    // if(isCircularList(head)) {
    //     cout << "List is circular" << endl;
    // } else {
    //     cout << "List is not circular" << endl;
    // }

    return 0;
}
