/* a Node of the doubly linked list
class Node {
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int x) {
		data = x;
		next = nullptr;
		prev = nullptr;
	}
};
*/

class Solution {
	public:
	
	// Function to delete a specified node from the linked list
	Node* deleteAllOccurOfX(Node* head, int x) {
		Node* curr = head;
		// code here
		
		while (curr) {
			Node* nextNode = curr->next;
			
			if (curr->data == x) {
				
				if (curr->prev == nullptr) {
					head = curr->next;
				} else {
					curr->prev->next = curr->next;
				}
				
				if (curr->next != nullptr) {
					curr->next->prev = curr->prev;
				}
				
				delete curr;
			}
			
			curr = nextNode;
		}
		
		return head;
	}
};
