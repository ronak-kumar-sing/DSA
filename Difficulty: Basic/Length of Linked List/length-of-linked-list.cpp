/* Structure of linked list Node
class Node {
	public:
	int data;
	Node *next;
	
	Node(int x) {
		data = x;
		next = nullptr;
	}
};
*/
class Solution {
	public:
	int getCount(Node* head) {
		// Code here
		int cnt = 0;
		while(head != nullptr) {
			head = head->next;
			cnt++;
		}
		return cnt;
	}
};
