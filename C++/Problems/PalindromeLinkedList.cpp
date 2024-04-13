// Reversing a linked list
ListNode* reversed_head = nullptr;
ListNode* current = head;

// Reverse the list
while (current) {
    // Store the next node in the original list
    ListNode* next = current->next;

    // Point the current node's next pointer to the reversed list's head
    current->next = reversed_head;

    // Update the reversed list's head to the current node
    reversed_head = current;

    // Move to the next node in the original list
    current = next;
}



/// This approach of mine doens't work
 bool isPalindrome(ListNode* head) {
    if (!head || !head->next) {
        return true; // Empty list or single-node list is considered palindrome
    }

    ListNode* reversed_head = nullptr;
    ListNode* current = head;

    // Reverse the list
    while (current) {
        ListNode* next = current->next;
        current->next = reversed_head;
        reversed_head = current;
        current = next;
    }

    // Compare original list with reversed list
    ListNode* original = head;
    ListNode* reversed = reversed_head;

    while (original) {
        if (original->val != reversed->val) {
            return false; // Not a palindrome
        }
        original = original->next;
        reversed = reversed->next;
    }

    return true; // Palindrome
}

// Have to look into the solution fo reversign tform the middle of the linked list.