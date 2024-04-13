// Should probably memorize while loops for linked list
// plus how to get their count and stuff.




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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    int length = 0;
    ListNode* current_head = head;

    // Calculate the length of the list
    while (current_head != nullptr) {
        length++;
        current_head = current_head->next;
    }

    // Reset current_head to the beginning of the list
    current_head = head;

    int current_length = 1;

    // Traverse to the node before the one to be removed
    while (length - current_length > n) {
        current_length++;
        current_head = current_head->next;
    }

    // Handle different cases for removing the node
    if (n == length) {
        // Remove the first node
        return head->next;
    } else if (n == 1) {
        // Remove the last node
        current_head->next = nullptr;
        return head;
    } else {
        // Remove a node in the middle
        current_head->next = current_head->next->next;
        return head;
       }
    }
};