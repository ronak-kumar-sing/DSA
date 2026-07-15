/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next; // break logic for even size of list show
                                     // the correct middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (left && right) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if (left)
            temp->next = left;
        else
            temp->next = right;

        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* middle = findMiddle(head);
        ListNode* leftList = head;
        ListNode* rightList = middle->next;
        middle->next = nullptr;

        ListNode* left = sortList(leftList);
        ListNode* right = sortList(rightList);

        return mergeList(left, right);
    }
};