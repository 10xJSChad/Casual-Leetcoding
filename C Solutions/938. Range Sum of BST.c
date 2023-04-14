// Solution using a stack.
// I initially solved it with basic recursion,
// but I figured I'd make it a bit more fun and
// throw a linked list at it.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// ListNode already in use by some other leetcode thingy >:(
struct ListNode_ {
    struct TreeNode *tree_node;
    struct ListNode_ *next;
};

int rangeSumBST(struct TreeNode* root, int low, int high){
    struct ListNode_* stack_head = (struct ListNode_*) malloc(sizeof(struct ListNode_));
    struct TreeNode* curr_node = root;
    int tree_sum = 0;

    // Initialize dummy head
    stack_head->next = stack_head;
  
    while(true){
        int node_val = curr_node->val;
        if(node_val >= low && node_val <= high)
            tree_sum += node_val;

        if(curr_node->right){
            struct ListNode_ *new_node = (struct ListNode_*) malloc(sizeof(struct ListNode_));
            new_node->tree_node = curr_node->right;
            new_node->next = stack_head->next;
            stack_head->next = new_node;
        }

        if(curr_node->left){
            curr_node = curr_node->left;
            continue;
        }
            
        if (stack_head->next == stack_head)
            return(tree_sum);

        curr_node = stack_head->next->tree_node;
        stack_head->next = stack_head->next->next;
    }
    return(tree_sum);
}
