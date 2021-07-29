# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        nodeToStr = ""
        while (head != None):
            nodeToStr += str(head.val)
            head = head.next
        return nodeToStr == nodeToStr[::-1]
