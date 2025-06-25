#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
private:
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail(Node*& head, Node*& tail, int val) {
        Node* temp = new Node(val);
        
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* first, Node* second) {
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while (first != NULL || second != NULL || carry != 0) {
            int val1 = (first != NULL) ? first->data : 0;
            int val2 = (second != NULL) ? second->data : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if (first != NULL) first = first->next;
            if (second != NULL) second = second->next;
        }
        return ansHead;
    }

public:
    // Function to add two numbers represented by linked lists
    Node* addTwoLists(Node* first, Node* second) {
        // Step 1: Reverse both lists
        first = reverse(first);
        second = reverse(second);

        // Step 2: Add the reversed lists
        Node* ans = add(first, second);

        // Step 3: Reverse the result to get final sum
        ans = reverse(ans);
        return ans;
    }
};


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Number 1: 243 (3->4->2)
    Node* first = new Node(2);
    first->next = new Node(4);
    first->next->next = new Node(3);

    // Number 2: 564 (4->6->5)
    Node* second = new Node(5);
    second->next = new Node(6);
    second->next->next = new Node(4);

    Solution sol;
    Node* result = sol.addTwoLists(first, second);

    cout << "Sum: ";
    printList(result);  // Expected Output: 8->0->7 (807)

    return 0;
}
