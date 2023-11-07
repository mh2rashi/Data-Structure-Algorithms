# the brute force method of doing this would be to get all the nodes in a list and then pop
# n-th element from the end of the list and ten create a new linked list

# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
      self.val = val
      self.next = next


def removeNthFromEnd(head,n):

    # function to check how many nodes we have from our original linked-list
    def traverse(list1):
        value = 0
        while list1:
            value += 1
            list1 = list1.next
        return value

    # checking number of nodes
    nodes = traverse(head)
    # checking which node to take out
    target = nodes - n
    i = 0
    # while loop
    temp_head = head
    while head:
        if i == target and target == 0:
            return head.next
        elif i + 1 == target and target == nodes - 1:
            head.next = None
            return temp_head
        if i + 1 == target:
            head.next = head.next.next
            head = head.next
            i += 1
        else:
            head = head.next
            i += 1
    return temp_head


a = ListNode(1)
a.next = ListNode(2)
a.next.next = ListNode(3)
a.next.next.next = ListNode(4)
a.next.next.next.next = ListNode(5)


b = ListNode(1)
b.next = ListNode(2)
b.next.next = ListNode(4)
b.next.next.next = ListNode(5)


assert removeNthFromEnd(a,2) == b