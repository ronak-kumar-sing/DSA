/*
class Node {
	public:
	int data;
	Node *next;
	
	Node(int x) {
		data = x;
		next = NULL;
	}
};
*/

class Solution {
	public:
	int lengthOfLoop(Node *head) {
		// code here
		
		Node * fast = head;
		Node * slow = head;
		
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			
			if (slow == fast) {
				
				Node * ptr = head;
				Node * prev;
				while (ptr != slow) {
					ptr = ptr->next;
					prev = slow;
					slow = slow->next;
				}
				
				int cnt = 1;
				while (ptr != prev) {
					ptr = ptr->next;
					cnt++;
				}
				
				return cnt;
			}
		}
		
		return 0;
		
	}
};
