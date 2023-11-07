# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
      self.val = val
      self.next = next

def swapPairs(head):
    temp_head = head
    while head:
        if head.next:
            curr = head.val
            nex = head.next.val
            head.val = nex
            head.next.val = curr
            head = head.next.next
        else:
            return temp_head
    return temp_head

a = ListNode(1)
a.next = ListNode(2)
a.next.next = ListNode(3)
a.next.next.next = ListNode(4)


b = ListNode(2)
b.next = ListNode(1)
b.next.next = ListNode(4)
b.next.next.next = ListNode(3)
