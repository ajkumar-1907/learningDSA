#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class Solution {
  private:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(head == NULL || head->next == NULL) {
            return true;
        }
        
        // Step 1: Find middle of the list
        Node* middle = getMid(head);

        // Step 2: Reverse the second half of the list
        Node* temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: Compare both halves
        Node* head1 = head;
        Node* head2 = middle->next;

        while(head2 != NULL) {
            if(head1->data != head2->data) {
                // Optional: Restore the list before returning
                middle->next = reverse(middle->next);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Restore the list before returning
        middle->next = reverse(middle->next);

        return true;
    }
};


int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    Solution sol;
    if (sol.isPalindrome(head))
        cout << "List is a palindrome" << endl;
    else
        cout << "List is not a palindrome" << endl;

    return 0;
}
