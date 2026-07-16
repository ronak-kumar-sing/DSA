/* Structure of linked list Node
class Node {
	public:
	int data;
	Node* next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
	public:
	Node* addOne(Node* head) {
		// code here
		Node* dummy = new Node(0);
		dummy->next = head;
		Node* prev = dummy;
		Node* temp = head;
		
		while (temp->next) {
			if (temp->data != 9)
				prev = temp;
			temp = temp->next;
		}
		
		if (temp->data < 9)
			temp->data = temp->data + 1;
		else {
			prev->data++;
			prev = prev->next;
			while (prev) {
				prev->data = 0;
				prev = prev->next;
			}
		}
		
		if(dummy->data == 1) return dummy;
		
		return head;
	}
};
