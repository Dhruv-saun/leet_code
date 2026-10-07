/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        Node* curr = head;

        // Step 1: Insert copied nodes between original nodes
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // Step 2: Set random pointers of copied nodes
        curr = head;

        while (curr != nullptr) {
            if (curr->random != nullptr)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // Step 3: Separate original and copied lists
        curr = head;
        Node* copyHead = head->next;

        while (curr != nullptr) {
            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != nullptr)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return copyHead;
    }
};