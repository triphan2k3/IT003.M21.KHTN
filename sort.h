#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class quick_sort
{
    public:
        vector<T> a; // array
        int n; // size off array = a.size()
        quick_sort(vector<T> a)
        {
            this -> a = a;
            n = a.size();
        }

        void sort(int l, int r)
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
        
        void sort()
        {
            sort(0,n-1);
        }

        string is_Sorted() {
            for (int i = 0; i + 1 < n; i++)
                if (a[i] > a[i+1]) return "Quick Sort Check: Unsorted\n";
            return "Quick Sort Check: Sorted\n";
        }
};

template <typename T>
class merge_sort {
    public:
        vector<T> a; // array
        int n; // size off array = a.size()
        merge_sort(vector<T> a) {
            this -> a = a;
            n = a.size();
        }
        
        void gop(int l, int r, int mid) {
            vector<T> b;
            int i = l, j = mid + 1;
            while (i <= mid && j <= r) {
                if (a[i] < a[j])
                    b.push_back(a[i++]);
                else
                    b.push_back(a[j++]);
            }
            while (i <= mid)
                b.push_back(a[i++]);
            while (j <= r)
                b.push_back(a[j++]);
            for(int i = l; i <= r; i++) 
                a[i] = b[i-l];
        }

        void sort(int l, int r) {
            if (l >= r) return;
            int mid = (l + r) >> 1;
            sort(l, mid);
            sort(mid + 1, r);
            gop(l, r, mid);
        }
        
        void sort()
        {
            sort(0,n-1);
        }

        string is_Sorted() {
            for (int i = 0; i + 1 < n; i++)
                if (a[i] > a[i+1]) return "Merge Sort Check: Unsorted\n";
            return "Merge Sort Check: Sorted\n";
        }
};

template <typename T>
class heap_sort{
    public:
        vector<T> a; // array
        int n; // size off array = a.size()
        vector<T> heap;
        heap_sort(vector<T> a) {
            this -> a = a;
            n = a.size();
        }

        void push(T value) {
            heap.push_back(value);
            int id = heap.size();
            while (id != 1) {
                int par = id >> 1;
                if (heap[par - 1] < heap[id - 1]) break;
                swap(heap[par - 1], heap[id - 1]);
                id = par;
            }
            return;
        }

        T pop() {
            T ret = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            int id = 1;
            while (id*2 <= heap.size()) {
                int idLeft = id*2;
                int idRight = min(id*2 + 1, (int)heap.size());
                if (min(heap[idLeft - 1], heap[idRight - 1]) > heap[id - 1]) break;
                if (heap[idLeft - 1] < heap[idRight - 1])
                    swap(heap[idLeft - 1], heap[id - 1]), id = idLeft;
                else
                    swap(heap[idRight - 1], heap[id - 1]), id = idRight;
            }
            return ret;
        }

        void sort() {
            for (int i = 0; i < a.size(); i++)
                push(a[i]);
            for (int i = 0; i < a.size(); i++)
                a[i] = pop();
            return; 
        }
        string is_Sorted() {
            for (int i = 0; i + 1 < n; i++)
                if (a[i] > a[i+1]) return "Heap Sort Check: Unsorted\n";
            return "Heap Sort Check: Sorted\n";
        }
};

template <typename T>
class cplusplus_sort {
    public:
        vector<T> a;
        int n;
        cplusplus_sort(vector<T> a) {
            this -> a = a;
            n = a.size();
        }
        void sort() {
            std::sort(a.begin(), a.end());
            return;
        }
        string is_Sorted() {
            for (int i = 0; i + 1 < n; i++)
                if (a[i] > a[i+1]) return "C++ Sort Check: Unsorted\n";
            return "C++ Sort Check: Sorted\n";
        }
};