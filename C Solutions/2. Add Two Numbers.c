/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

inline void insert_node(struct ListNode* insertion_point_node)
{
    struct ListNode *new_node = (struct ListNode*) malloc(
        sizeof(struct ListNode)
    );
    
    new_node->val = 0;
    new_node->next = NULL;
    insertion_point_node->next = new_node;
}

inline void perform_addition(struct ListNode* curr_node_a, 
                             int num_a, int num_b)
{
    int carry_over = 0;
    int sum = num_a + num_b;

    if(sum > 9){
        carry_over = 1;
        curr_node_a->val = sum - 10;

        if(!curr_node_a->next)
            insert_node(curr_node_a);
            
        perform_addition(curr_node_a->next, 
                         curr_node_a->next->val, carry_over);
    }else{
        curr_node_a->val = sum;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* list_a, 
                               struct ListNode* list_b)
{
    struct ListNode* curr_node_a = list_a;
    struct ListNode* curr_node_b = list_b;
    
    int carry_over = 0;
    while(curr_node_b){
        perform_addition(curr_node_a, curr_node_a->val, 
                         curr_node_b->val);

        if(!curr_node_a->next && curr_node_b->next)
            insert_node(curr_node_a);

        curr_node_a = curr_node_a->next;
        curr_node_b = curr_node_b->next;
    }
    
    return(list_a);
}
