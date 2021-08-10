
#include "sort.h"

void print_array(int * array, int size) {


    for (int i = 0; i < size; i++) {

        printf("%d\t", array[i]);
    }

    printf("\r\n");
}

void swap(int * x, int * y) {

    int tmp = 0;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

void counting_sort(int * array, int l, int r) {


}


void merge_sort(int * array, int l, int r) {

    if (r <= l) {

        return;
    }

    int idx = 0;
    int m = (l+r)/2;

    int lp = l, rp = m+1;

    merge_sort(array, l, m);
    merge_sort(array, m+1, r);

    int * external_space = malloc(sizeof(int) * (r-l+1));
    if (external_space == NULL) {
        return;
    }

    while (idx < (r-l+1)) {

        if (lp == m+1) {

            external_space[idx++] = array[rp++];
            continue;
        }

        if (rp == r+1) {

            external_space[idx++] = array[lp++];
            continue;
        }

        if (array[lp] < array[rp]) {

            external_space[idx++] = array[lp++]; 
        } else {

            external_space[idx++] = array[rp++]; 
        }
    }

    for (int k = 0; k<r-l+1; k++) {

        array[l+k] = external_space[k];
    }

    free(external_space);
}

void shell_sort(int * array, int n) {

    int gap = n/2;

    while (gap > 0) {

        for (int i = 0; i< gap; i++) {

            for (int j = 0; i + (j + 1) * gap < n; j++)  {

                if (array[i + j*gap] > array[i + (j + 1) * gap]) {

                    swap(array+i+j*gap, array+i+(j+1)*gap);
                }

            }

        }
        gap = gap / 2;
    }
}

void adjust_heap(int * array, int n, int x) {

    int root = array[x];

    int idx = 2*x + 1;
    while (idx<n) {

        if (idx + 1 < n  && array[idx] < array[idx+1]) {

            idx = idx + 1;
        }

        if (array[idx] > root) {

            array[(idx-1)/2] = array[idx];
        } else {

            break;
        }

        idx = idx * 2 + 1;
    }

    array[(idx-1)/2] = root;
}

void heap_sort(int * array, int n) {

    int i = 0;

    for (i = n/2; i>=0; i--) {

        adjust_heap(array, n, i);
    }

    for (i = n-1; i>=0; i--) {

        swap(array+i, array+0);
        adjust_heap(array, i, 0);
    }
}

/*
 * root = 1
 * left = 2x
 * right = 2x +1
 *
 * root = 0
 * left = 2x + 1
 * right = 2x + 2*/

int get_left_child(int start_form_0, int parent) {

    int x = parent;

    if (start_form_0) {
        return 2 * x + 1;
    } else {
        return 2 * x;
    }

}

int get_right_child(int start_form_0, int parent) {

    int x = parent;

    if (start_form_0) {
        return 2 * x + 2;
    } else {
        return 2 * x + 1;
    }

}


void quick_sort(int * array, int l, int r) {

    if (l >= r) {

        return;
    }

    int m = l+1, n = r;

    while (1) {

        while (m < r && array[m] <= array[l]) {
            m++;
        }

        while (n > l && array[n] >= array[l]) {
            n--;
        }

        if (m < n) {
            swap(array+m, array+n);
        } else {
            break;
        }

    }

    swap(array+l, array+n);

    //print_array(array, r - l + 1); 

    quick_sort(array, l, n - 1);
    quick_sort(array, n + 1, r);
}

void bubble_sort(int * array, int l, int r) {

    int flag = 0;
    for (int i=l; i<r; i++) {

        flag = 0;
        for (int j=l; j<r-i; j++) {

            if (array[j] > array[j+1]) {

                swap(array+j, array+j+1);
                flag = 1;
            }           
        }

        if (!flag) {
            break;
        }
    }
}

void insert_sort(int * array, int l, int r) {

    for (int i = l; i < r; i++ ) {

        for (int j = i + 1; j > l; j--) {

            if (array[j] < array[j-1]) {

                swap(array+j, array+j-1);
                /*
                   tmp = array[j];
                   array[j] = array[j-1];
                   array[j-1] = tmp;
                   */
            }
        }
    }

}



void selection_sort(int * array, int l, int r) {

    int min = 0;
    int j = 0;

    for (int i = l; i < r; i++) {

        min = i;

        for (j=min+1; j <= r; j++) {

            if (array[j] < array[min]) {

                min = j;
            }

        }

        swap(array+min, array+i);

        /*
           tmp = array[min];
           array[min] = array[i];
           array[i] = tmp;

*/
        //    printf("%d, ", array[i]);

    }
}


int array[MIN_NUM] = {3, 4, 8, 5, 9, 6, 2, 1, 7, 199};
//int array[MIN_NUM] = {3, 4, 8, 3, 9, 6, 2, 1, 7, 5};


int test_selection_sort() {

    print_array(array, MIN_NUM);

    selection_sort(array, 0, 9);

    print_array(array, MIN_NUM);
}

int test_insert_sort() {

    print_array(array, MIN_NUM);

    insert_sort(array, 0, 9);

    print_array(array, MIN_NUM);
}

int test_bubble_sort() {

    print_array(array, MIN_NUM);

    bubble_sort(array, 0, 9);

    print_array(array, MIN_NUM);
}

int test_shell_sort() {

    print_array(array, MIN_NUM);

    shell_sort(array, 10);

    print_array(array, MIN_NUM);
}

int test_quick_sort() {

    print_array(array, MIN_NUM);

    quick_sort(array, 0, 9);

    print_array(array, MIN_NUM);
}

int test_merge_sort() {

    print_array(array, MIN_NUM);

    merge_sort(array, 0, 9);

    print_array(array, MIN_NUM);
}

int test_heap_sort() {

    print_array(array, MIN_NUM);

    heap_sort(array, 10);

    print_array(array, MIN_NUM);
}

void test_sort(void) {

    test_selection_sort();

    test_insert_sort();
}


