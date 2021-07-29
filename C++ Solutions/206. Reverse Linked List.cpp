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
    ListNode* newList;
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        while (current != NULL) {
            
            ListNode* temp = new ListNode;
            temp -> val = current -> val;;
            temp -> next = newList;
            newList = temp;
            current = current -> next;
        }
        return newList;
    }
};
