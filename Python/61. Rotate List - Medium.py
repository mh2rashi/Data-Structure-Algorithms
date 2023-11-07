# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
       self.val = val
       self.next = next

def rotateRight(head,k):
    






a = ListNode(0)
a.next = ListNode(1)
a.next.next = ListNode(2)

b = ListNode(1)
b.next = ListNode(2)
b.next.next = ListNode(3)
b.next.next.next = ListNode(4)
b.next.next.next.next = ListNode(5)

print(rotateRight(a,4))

print(rotateRight(b,2))