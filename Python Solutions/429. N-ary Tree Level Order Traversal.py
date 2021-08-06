"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root == None: return []
        order = [[root.val]]
        nodes = []
        count = 0
        for x in root.children:
            nodes.append(x)
            
        while True:
            flag = True
            tempNodes, tempOrder = [], []
            for x in nodes:
                tempOrder.append(x.val)
                flag = False
                for y in x.children:
                    tempNodes.append(y)
            
            if flag: return order
            if tempOrder != []: order.append(tempOrder); nodes = tempNodes
            
        return order
