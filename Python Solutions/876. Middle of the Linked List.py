# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        i = 0
        current = head
        while current != None:
            current = current.next
            i += 1    
        i = int(i / 2)
        if i == 0: return(head)
        for j in range(0, int(i)):
            head = head.next
            if j + 1 == i: return head
