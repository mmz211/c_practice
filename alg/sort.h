

#include <stdio.h>
#include <stdlib.h>

#define MIN_NUM 10

void print_array(int * array, int size); 

void swap(int * x, int * y); 

void counting_sort(int * array, int l, int r); 

void merge_sort(int * array, int l, int r); 

void shell_sort(int * array, int n); 

void adjust_heap(int * array, int n, int x); 

void heap_sort(int * array, int n); 

int get_left_child(int start_form_0, int parent); 

int get_right_child(int start_form_0, int parent); 

void quick_sort(int * array, int l, int r); 

void bubble_sort(int * array, int l, int r); 

void insert_sort(int * array, int l, int r); 

void selection_sort(int * array, int l, int r); 

int test_selection_sort(); 

int test_bubble_sort(); 

int test_insert_sort(); 

int test_shell_sort(); 

int test_quick_sort(); 

int test_merge_sort(); 

int test_heap_sort(); 

void test_sort(void); 


