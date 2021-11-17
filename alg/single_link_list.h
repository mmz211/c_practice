
//#define DESCENDING

typedef int elem_type;

//#pragma pack(1)

struct MY_SLL_NODE {

    struct MY_SLL_NODE * next;
    elem_type data;
};

typedef struct MY_SLL_NODE SLL_NODE;
typedef struct MY_SLL_NODE * SLL_PTR;


int init_sll(SLL_NODE ** list); 

int deinit_sll(SLL_NODE * list); 

void traverse_sll(SLL_NODE * list); 

int find_node_by_key(SLL_NODE * list, elem_type key, SLL_NODE ** result); 

int insert_in_order(SLL_NODE ** list, elem_type value);

int insert_at_tail(SLL_NODE ** list, elem_type value); 

int remove_node_by_prev(SLL_NODE ** list, SLL_NODE * prev, SLL_NODE * curr);

int remove_node_by_key(SLL_NODE ** list, elem_type key);

int remove_node(SLL_NODE ** list, SLL_NODE * target);

int merge_ordered_list(SLL_NODE * first_list, SLL_NODE * second_list, SLL_NODE ** result);

int reverse_list(SLL_NODE ** result);

int test_sigle_link_list(void); 


