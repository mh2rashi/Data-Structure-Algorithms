// Here's the solution

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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* reversed_head = nullptr;
        
        ListNode* current = head;
        
        while (current) {
            
            ListNode* current_next = current->next;
            
            current->next = reversed_head;
            reversed_head = current;
            
            current = current_next;
            
        }
        
    return reversed_head;
        
    }
};