class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def traverse(list1):
    value = 0
    while list1 != None:
        value += 1
        list1 = list1.next
    return value

def getIntersectionNode(headA,headB):
    difference = traverse(headA) - traverse(headB)
    if difference > 0:
        count_to = 0
        while count_to < difference:
            headA = headA.next
            count_to += 1
    headA
    if difference < 0:
        count_to = 0
        while count_to > difference:
            headB = headB.next
            count_to -= 1
    headB
    while headA != None and headB != None:
        if headA.val == headB.val:
            return headA.val
        else:
            headA = headA.next
            headB = headB.next
    return None







list_a = ListNode(3)
list_a.next = ListNode(4)
list_a.next.next = ListNode(5)
list_a.next.next.next = ListNode(6)

list_b = ListNode(1)
list_b.next = ListNode(2)
list_b.next.next = ListNode(5)
list_b.next.next.next = ListNode(6)

[4,1,8,4,5]
[5,0,1,8,4,5]

list_c = ListNode(4)
list_c.next = ListNode(1)
list_c.next.next = ListNode(8)
list_c.next.next.next = ListNode(4)
list_c.next.next.next.next = ListNode(5)

list_d = ListNode(5)
list_d.next = ListNode(0)
list_d.next.next = ListNode(1)
list_d.next.next.next = ListNode(8)
list_d.next.next.next.next = ListNode(4)
list_d.next.next.next.next.next = ListNode(5)


assert getIntersectionNode(list_a,list_b) == 5
assert getIntersectionNode(list_c,list_d) == 1

