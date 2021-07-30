# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):     
        if node.next != None: node.val = node.next.val
        if node.next.next == None:
            node.next = None
        if node.next != None: 
            self.deleteNode(node.next)
