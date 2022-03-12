#include <bits/stdc++.h>
#include "sort.h"
#define TASK "SORT"
using namespace std;

int main() {
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);

    clock_t begin_input = clock();
    int n; cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i]; 
    clock_t end_input = clock();
    
    clock_t begin_quick_sort = clock();
    quick_sort<double> qs(a);
    //cout<< qs.is_Sorted();
    qs.sort();
    cout << qs.is_Sorted();
    clock_t end_quick_sort = clock();
    
    clock_t begin_merge_sort = clock();
    merge_sort<double> ms(a);
    //cout<< ms.is_Sorted();
    ms.sort();
    cout << ms.is_Sorted();
    clock_t end_merge_sort = clock();

    clock_t begin_heap_sort = clock();
    heap_sort<double> hs(a);
    //cout<< hs.is_Sorted();
    hs.sort();
    cout << hs.is_Sorted();
    clock_t end_heap_sort = clock();

    printf("INPUT TIME: %.2f\n",(double)(end_input - begin_input) / CLOCKS_PER_SEC);
    printf("QUICK SORT TIME: %.2f\n",(double)(end_quick_sort - begin_quick_sort) / CLOCKS_PER_SEC);
    printf("MERGE SORT TIME: %.2f\n",(double)(end_merge_sort - begin_merge_sort) / CLOCKS_PER_SEC);
    printf("HEAP SORT TIME: %.2f\n",(double)(end_heap_sort - begin_heap_sort) / CLOCKS_PER_SEC);
}