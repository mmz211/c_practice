
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tools.h"

/*
 * low case letters
 *
 * */

#define LOWCASE_LETTER  'a'

struct Trie_Node {

    _Bool flag;
    char charicter;
    struct Trie_Node * next[26];
};

typedef struct Trie_Node Node;

static Node * root;


int init_trie(void) {

    root = (Node *)malloc(sizeof(Node));
    if (root == NULL) {

        return CODE_API_RETURN_ERR; 
    }
    root->flag = false;

    return CODE_OK;
}

int insert_word(char * word) {

    Node * cursor = root;
    int w_len = strlen(word);
    int char_index;

    for (int i=0; i<w_len; i++) {

        char_index = *(word + i) - 'a';
        if (cursor->next[char_index] == NULL) {

            cursor->next[char_index] = (Node *) malloc(sizeof(Node));
            if (cursor->next[char_index] == NULL) {

                return CODE_API_RETURN_ERR;
            }

        } 
        cursor = cursor->next[char_index];

    }

    if (cursor->flag) {

        return CODE_TRIE_WORD_ALREADY_EXISTS;
    } else {

        cursor->flag = true;
        return CODE_TRIE_INSERT_NEW_WORD;
    }
}

int search_word(char * word) {

    Node * cursor = root;
    int w_len = strlen(word);
    int char_index;

    for (int i=0; i<w_len; i++) {

        char_index = *(word + i) - 'a';
        if (cursor->next[char_index] == NULL) {

            return CODE_TRIE_NOT_FOUND;
        }
        cursor = cursor->next[char_index];
    }

    if (cursor->flag) {
        return CODE_TRIE_FOUND;
    } else {
        return CODE_TRIE_NOT_FOUND;
    }

}

int deinit_trie(Node * root) {

    if (root == NULL) {
    
        return CODE_OK;
    }

    for (int i=0; i<26; i++) {
    
        deinit_trie(root->next[i]);
    }

    free(root);

    return CODE_OK;
}

int test_trie(void) {

    int ret = 0;

    char input_buff[128] = {0};
    int words_cnt = 0;

    printf("input how many words you want to insert\r\n");
    scanf("%d", &words_cnt);

    ret = init_trie();
    if (ret) {
        printf("init failed, %d\r\n", ret);
        return EXIT_FAILURE;
    } else {
        printf("init trie %d\r\n", ret);
    }

    printf("input words you want to insert\r\n");
    for (int i=0; i<words_cnt; i++) {

        scanf("%[a-z]s", input_buff);

        ret = insert_word(input_buff);
        switch (ret) {

            case CODE_TRIE_INSERT_NEW_WORD: 
                printf("insert successful\r\n");
                break;
            case CODE_TRIE_WORD_ALREADY_EXISTS: 
                printf("word already exists\r\n");
                break;
            default:
                printf("insert failed\r\n");
                break;
        }

    }

    printf("input words you want to search\r\n");
    for (int i=0; i<words_cnt; i++) {

        scanf("%s", input_buff);

        ret = search_word(input_buff);
        if (ret == CODE_TRIE_NOT_FOUND) {

            printf("word not found\r\n");
        } else if (ret == CODE_TRIE_FOUND) {

            printf("word found\r\n");
        } else {}
    }

    ret = deinit_trie(root);
    printf("deinit trie %d\r\n", ret);

}
