
#include <iostream>
#include <algorithm>

using namespace std;

struct node {

    int x, y;

    bool operator< (const node &b) const {
        return this->x > b.x;
    }
};


bool cmp_node(const node &a, const node &b) {

    if (a.x == b.x) {
        return a.y > b.y;
    }
    return a.x > b.x;
}

int main(){

    /*
    node t[10] {
        {12, 3},
        {15, 3},
        {19, 3},
        {92, 3},
        {72, 3},
        {15, 3},
        {62, 3},
        {22, 3},
        {42, 3},
        {32, 3},
    };
    */
    node t[10] {
        [0] = {32, 3},
        [1] = {12, 3},
        [2] = {15, 7},
        [3] = {19, 3},
        [4] = {92, 3},
        [5] = {72, 3},
        [6] = {15, 3},
        [7] = {62, 3},
        [8] = {22, 3},
        [9] = {42, 3},
    };

    //sort(t, t+11, cmp_node);

    sort(t, t+11);

    for (int i =0; i<10; i++) {
    
        cout << t[i].x << " " << t[i].y << endl;
    }

    return 0;
}

