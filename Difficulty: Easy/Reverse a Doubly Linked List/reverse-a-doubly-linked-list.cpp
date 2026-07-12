/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here

        while(head != nullptr){
            Node *temp = head->next;
            head->next = head->prev;
            head->prev = temp;
            if(head->prev == nullptr) return head;
            head = head->prev;
        }
        
        return head;
    }
};