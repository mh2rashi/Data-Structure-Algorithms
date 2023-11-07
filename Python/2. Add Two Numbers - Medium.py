class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

def addTwoNumbers(l1,l2):
    list_1 = ''
    list_2 = ''
    while l1 != None:
        list_1 += str(l1.val)
        l1 = l1.next
    while l2 != None:
        list_2 += str(l2.val)
        l2 = l2.next
    x = str(int(list_1[::-1]) + int(list_2[::-1]))[::-1]
    o_head = ListNode(x[0])
    head = o_head
    for i in range(1,len(x)):
        head.next = ListNode(int(x[i]))
        head = head.next
    return o_head

a = ListNode(2)
a.next = ListNode(4)
a.next.next = ListNode(3)

b = ListNode(5)
b.next = ListNode(6)
b.next.next = ListNode(4)

