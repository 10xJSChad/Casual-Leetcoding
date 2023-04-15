/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* list_a_head; // GLOBAL!
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


// Inserts node_b after node_a
inline void insert_after(struct ListNode* node_a,
                         struct ListNode* node_b)
{
    node_b->next = node_a->next;
    node_a->next = node_b;
}


// Inserts node_b before node_a
inline void insert_before(struct ListNode** node_a,
                   struct ListNode* node_b)
{

    if(list_a_head == *node_a){
        list_a_head = node_b;
    }

    node_b->next = *node_a;
    *node_a = node_b;

}


inline void insert_sorted(struct ListNode** list_a,
                          struct ListNode* list_b)
{

    list_b->next = NULL; // Disconnect list_b from its list
                         // don't want any extra nodes sneaking in

    while(*list_a){

        if(list_b->val <= (*list_a)->val){
            insert_before(list_a, list_b);
            return;
        }

        // ugly.
        if(!(*list_a)->next
           || (list_b->val >= (*list_a)->val
           &&  list_b->val <= (*list_a)->next->val)){

            insert_after(*list_a, list_b);
            return;
        }
        *list_a = (*list_a)->next;
    }

}


struct ListNode* mergeTwoLists(struct ListNode* list_a,
                               struct ListNode* list_b)
{

    list_a_head = list_a; // Store initial head, it's the easiest way
                          // to deal with all the pointer stuff coming up
                          // see insert_before() to see why.

    // Return list_b if list_a is empty
    if(!list_a){
        return(list_b);
    }

    // We will be inserting list_b into list_a
    while(list_b){
        struct ListNode* list_b_next = list_b->next;
        insert_sorted(&list_a, list_b);
        list_b = list_b_next;
    }

    return(list_a_head);

}
