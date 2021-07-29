# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution: 
    #This is my second solution, a lot more elegant.
    #My first solution can be found below
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root == None or root.val == val: return root
        if root.val > val: return(self.searchBST(root.left, val))
        else: return self.searchBST(root.right, val)
        
        
#class Solution: 
#    def search(self, current, val):
#        if current == None: return False
#        if current.val == val: 
#            return current
#        
#        if current.val > val:
#            current = current.left
#            return(self.search(current, val))
#        else:
#            current = current.right
#            return(self.search(current, val))
#        
#    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
#        self.subtree = TreeNode(0, None, None)
#        self.emptySubtree = TreeNode()
#        
#        result = self.search(root, val)
#        if result == False: return(self.emptySubtree.left)
#        else: return result
