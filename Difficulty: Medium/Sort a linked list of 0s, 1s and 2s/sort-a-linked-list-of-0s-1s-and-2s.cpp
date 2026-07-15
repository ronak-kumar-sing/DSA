/* Node is defined as
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
	Node* segregate(Node* head) {
		Node* dummyHeadZero = new Node(-1);
		Node* dummyHeadOne = new Node(-1);
		Node* dummyHeadTwo = new Node(-1);
		
		Node* zero = dummyHeadZero;
		Node* one = dummyHeadOne;
		Node* two = dummyHeadTwo;
		
		while (head) {
			if (head->data == 0) {
				zero->next = head;
				zero = zero->next;
			} else if (head->data == 1) {
				one->next = head;
				one = one->next;
			} else {
				two->next = head;
				two = two->next;
			}
			head = head->next;
		}
		if (dummyHeadOne->next)
			zero->next = dummyHeadOne->next;
		else
			zero->next = dummyHeadTwo->next;
		one->next = dummyHeadTwo->next;
		two->next = nullptr;
		return dummyHeadZero->next;
	}
};
