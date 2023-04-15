/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 // Inserts an empty node into insertion_point_node->next;
inline void insert_node(struct ListNode* insertion_point_node)
{
    struct ListNode *new_node = (struct ListNode*) malloc(
        sizeof(struct ListNode)
    );
    
    new_node->val = 0;
    new_node->next = NULL;
    insertion_point_node->next = new_node;
}

inline void perform_addition(struct ListNode* node_a, 
                             int num_a, int num_b)
{
    int carry_over = 0;
    int sum = num_a + num_b;

    if(sum > 9){
        carry_over = 1;
        node_a->val = sum - 10;

        if(!node_a->next)
            insert_node(node_a);
            
        perform_addition(node_a->next, 
                         node_a->next->val, carry_over);
    }else{
        node_a->val = sum;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* node_a, 
                               struct ListNode* node_b)
{
    struct ListNode* list_a_head = node_a;
    
    while(node_b){
        perform_addition(node_a, node_a->val, 
                         node_b->val);

        if(!node_a->next && node_b->next)
            insert_node(node_a);

        node_a = node_a->next;
        node_b = node_b->next;
    }
    
    return(list_a_head);
}
