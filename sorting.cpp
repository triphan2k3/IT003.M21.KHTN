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

    clock_t begin_cplusplus_sort = clock();
    cplusplus_sort<double> cs(a);
    //cout<< gs.is_Sorted();
    cs.sort();
    cout << cs.is_Sorted();
    clock_t end_cplusplus_sort = clock();

    printf("INPUT TIME: %d\n",(int)(end_input - begin_input));
    printf("QUICK SORT TIME: %d\n",(int)(end_quick_sort - begin_quick_sort));
    printf("MERGE SORT TIME: %d\n",(int)(end_merge_sort - begin_merge_sort));
    printf("HEAP SORT TIME: %d\n",(int)(end_heap_sort - begin_heap_sort));
    printf("C++ SORT TIME: %d\n",(int)(end_cplusplus_sort - begin_cplusplus_sort));
}