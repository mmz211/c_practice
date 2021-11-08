
#include "tools.h"

#include "sort.h"
#include "avl_tree.h"
#include "bin_search_tree.h"
#include "single_link_list.h"
#include "queue.h"
#include "queue_cycle.h"
#include "stack.h"
#include "heap.h"
#include "trie.h"

extern int test_time(void);

int main(int argc, char ** argv) {

    test_trie();
/*
    printf("argc = %d\r\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
*/
    // test_time();

    // test_heap();

    // test_stack();

    //test_cycle_queue();

    //test_queue();

    //test_avl_tree_case();

    //test_bin_tree_case(); 
    
    //test_sigle_link_list();

    //test_sort();

    return 0;
}

