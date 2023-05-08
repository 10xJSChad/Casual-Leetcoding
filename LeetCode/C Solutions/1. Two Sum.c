#define mod(a, b) (((a % b) + b) % b)
#define Dict_Compress(dict, key) (mod(key, dict.size))
#define Dict_GetDictNode(dict, key) (dict.slots[Dict_Compress(dict, key)])
#define Dict_Contains(dict, key) !(Dict_GetKeyDictNode(dict, key) == NULL)

typedef struct DictNode {
    int key;
    int val;
    struct  DictNode* next;
} DictNode;


typedef struct Dict {
    int size;
    DictNode** slots;
} Dict;


inline
DictNode*
DictNode_Create (
        int key,
        int val)
{
    DictNode* created_node = (DictNode*) malloc(sizeof(DictNode));
    created_node->key = key;
    created_node->val = val;
    created_node->next = NULL;
    return created_node;
}


inline
void
DictNode_Append (
        DictNode* head,
        DictNode* node)
{
    DictNode** temp = &head;

    while ((*temp)->next)
        temp = &(*temp)->next; 

    (*temp)->next = node;
}


inline
void
DictNode_DestroyList (
        DictNode* head)
{
    DictNode* prev;

    while (head) {
        prev = head;
        head = head->next;
        free(prev);
    }
}


inline
Dict
Dict_Create (
        int elements)
{
    int created_dict_size = 2;

    while (created_dict_size < elements)
        created_dict_size = created_dict_size << 1;

    Dict created_dict;
    created_dict.size = created_dict_size + 1;
    created_dict.slots = (DictNode**) calloc(created_dict.size, sizeof(DictNode));
    return created_dict;
}


inline
void
Dict_Add (
        Dict dict,
        int key,
        int val)
{
    DictNode* key_node = Dict_GetDictNode(dict, key);
    
    if (key_node)
        DictNode_Append(key_node, DictNode_Create(key, val));
    else
        Dict_GetDictNode(dict, key) = DictNode_Create(key, val);
}


inline
DictNode*
Dict_GetKeyDictNode (
        Dict dict,
        int key)
{
    DictNode* element_slot_node = Dict_GetDictNode(dict, key);

    while (element_slot_node
            && element_slot_node->key != key)
        element_slot_node = element_slot_node->next;
        
    return element_slot_node;
}


inline
int
Dict_Get (
        Dict dict,
        int key)
{
    return Dict_GetKeyDictNode(dict, key)->val;
}


inline
void
Dict_Destroy (
        Dict dict)
{
    for (int i = 0; i < dict.size; ++i)
        if (dict.slots[i])
            DictNode_DestroyList(dict.slots[i]);
}


int* 
twoSum (
    int* nums,
    int numsSize,
    int target,
    int* returnSize)
{
    int* ans = (int*) malloc(2 * sizeof(int));
    Dict nums_indices = Dict_Create(numsSize);
    
    for (int i = 0; i < numsSize; ++i) {
        int required_num = target - nums[i];

        if (Dict_Contains(nums_indices, required_num)) {
            ans[0] = i;
            ans[1] = Dict_Get(nums_indices, required_num);

            Dict_Destroy(nums_indices);
            *returnSize = 2;
            return ans;
        }

       Dict_Add(nums_indices, nums[i], i);
    }
    
    return NULL;
}
