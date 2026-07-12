/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        
        if(head == nullptr) return head;
        int cnt = 0;

        Node *temp = head;
        while(cnt < p){
            temp = temp->next;
            cnt++;
        }
        
        Node* newOne = new Node(x);
        newOne->next = temp->next;
        if(temp->next != nullptr) temp->next->prev = newOne;
        newOne->prev = temp;
        temp->next = newOne;
        return head;
    }
};