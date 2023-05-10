#define NODE_VAL_TO_ANSWER(node) ans[*returnSize] = root->val; ++*returnSize;
#define STACK_EMPTY (stack[1] == NULL || stack_index <= 0)
#define STACK_PUSH(node) stack[++stack_index] = node
#define STACK_POP() stack[stack_index--]
#define STACK_PUSH_NULL_POP_ASSIGN(destination_node, source_node) \
    STACK_PUSH(source_node);            \
    source_node = NULL;                 \
    destination_node = STACK_POP()


int* 
inorderTraversal(
    struct TreeNode* root, 
    int* returnSize)
{
    *returnSize = 0; // returnSize does not reset after a test case */

    if (!root)
        return;

    // tree will never be larger than 100 nodes
    struct TreeNode** stack = calloc(101, sizeof(struct TreeNode*));
    int* ans = malloc(101 * sizeof(int));
    uint8_t stack_index = 0;

LOOP_START:;
    if (root->left) {
        STACK_PUSH(root);
        STACK_PUSH_NULL_POP_ASSIGN(root, root->left);
        goto LOOP_START;
    } else {
        NODE_VAL_TO_ANSWER(root);
    }

    if (root->right) {
        STACK_PUSH_NULL_POP_ASSIGN(root, root->right);
        goto LOOP_START;
    }

    if (STACK_EMPTY)
        return ans;

    root = STACK_POP();
    goto LOOP_START;
}
