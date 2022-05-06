#include<iostream>
#include "rbtree.h"

using namespace std;
int main() {
    RBTree a; 
    
    freopen("OUTPUT.txt","w",stdout);

    for (int i = 1; i<=7; i++) {
        a.insert(i); 
    //a._display_tree();
        //return 0;
        //a.printTree(a.root);
        //cout << "\n";
    } 
    return 0;
    for (int i = 1; i<=7; i++)
        a.erase(i);

    
    // a._display_tree();
    // a.erase(3);
    // a._display_tree(); return 0;

    // Node *x = a.lower_bound(9);
    // x = a.Next(x);
    // cout << x->getData();
    // cout << "ok";
    // return 0;
    // for (int i = 1; i<=16; i++) {
    //     a._display_tree();
    //     a.erase(i);
    // }
    
    // a._display_tree();
    // for (int i = 1; i<=16; i++) {
    //     a.insert(i);
    //     a.printTree(a.root);
    //     cout << "\n";
    // }
    // a._display_tree();
}