#include <iostream>
using namespace std;


class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to find the middle of the list
node* findMid(node* head) {
    node* slow = head;
    node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
node* merge(node* left, node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    node* ans = new node(-1);
    node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    return ans->next;
}

// Merge sort for linked list
node* mergeSort(node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    node* mid = findMid(head);
    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

// Sample usage
int main() {
    // Creating an unsorted linked list: 5 -> 3 -> 8 -> 2 -> 1
    node* head = new node(5);
    head->next = new node(3);
    head->next->next = new node(8);
    head->next->next->next = new node(2);
    head->next->next->next->next = new node(1);

    cout << "Original List: ";
    printList(head);

    // Sorting the list using merge sort
    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
