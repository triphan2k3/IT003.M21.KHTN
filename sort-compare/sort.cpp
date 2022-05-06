/*
#include "sort.h"

template <typename T>
quick_sort<T>::quick_sort(vector<T> a)
{
    this -> a = a;
    n = a.size();
}

template <typename T>
void quick_sort<T>::sort(int l, int r)
{
    if (l >= r) return;
    T key = a[(l + r) >> 1];
            
    int newL = l;
    int newR = r;
    while (newL <= newR)
    {
        while (a[newL] < key) ++newL;
        while (a[newR] > key) --newR;
        if (newL <= newR)
            swap(a[newL], a[newR]), ++newL, --newR;
    }
    sort(l, newR);
    sort(newL, r);
}

template <typename T>
void quick_sort<T>::sort()
{
    sort(0,n-1);
}

template <typename T>
string quick_sort<T>::is_Sorted() 
{
    for (int i = 0; i + 1 < n; i++)
        if (a[i] > a[i+1]) return "Quick Sort Check: Unsorted\n";
    return "Quick Sort Check: Sorted\n";
}

template class quick_sort<int>;
template class quick_sort<double>;
*/