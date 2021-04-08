/**
 * @file main.cpp
 * @brief This is a test of CMake, doxygen, and GitHub.
 * @details This is the long brief at the top of main.cpp.
 * @author Benson Nyakango
 * @date 1/28/2021
 * 
 */

#include <iostream>
#include <assert.h>
using namespace std;

//Array Implementation

template <typename T>
struct array {
   T *a;
int length;

array(int len) {
length = len;
a = new T[length];
}

T& operator[](int i) {
assert(i >= 0 && i < length);
return a[i];
}

array<T>& operator=(array<T> &b) {
if (a != NULL) delete[] a;
a = b.a;
b.a = NULL;
length = b.length;
return *this;
}






// Array Stack Implementation

//array<T> a;
int n;
int size() {
return n;
}

T get(int i) {
return a[i];
}
T set(int i, T x) {
T y = a[i];
a[i] = x;
return y;
}

void add(int i, T x) {
if (n + 1 > a.length) resize();
for (int j = n; j > i; j--)
a[j] = a[j - 1];
a[i] = x;
n++;
}

T remove(int i) {
T x = a[i];
for (int j = i; j < n - 1; j++)
a[j] = a[j + 1];
n--;
if (a.length >= 3 * n) resize();
return x;
}

void resize() {
array<T> b(max(2 * n, 1));
for (int i = 0; i < n; i++)
b[i] = a[i];
a = b;
}












template <typename B>
struct BinaryHeap { 
        
        int left(int i) {
            return 2*i + 1;
        }
        int right(int i) {
            return 2*i + 2;
        }
        int parent(int i) {
            return (i-1)/2;
        }
            
        array<B> a;
        int n;
        
        bool add(B x) {
            if (n + 1 > a.length) resize();
            a[n++] = x;
            bubbleUp(n-1);
            return true;
        }
        
        void bubbleUp(int i) {
        int p = parent(i);
        while (i > 0 && compare(a[i], a[p]) < 0) {
            a.swap(i,p);
            i = p;
            p = parent(i);
            }
        }
        
        B remove() {
            B x = a[0];
            a[0] = a[--n];
            trickleDown(0);
            if (3*n < a.length) resize();
            return x;
        }
        
        void trickleDown(int i) {
            
            do {
                int j = -1;
                int r = right(i);
                if (r < n && compare(a[r], a[i]) < 0) {
                    int l = left(i);
                    if (compare(a[l], a[r]) < 0) {
                        j = l;
                        } else {
                            j = r;
                        }
                    } else {
                        int l = left(i);
                        if (l < n && compare(a[l], a[i]) < 0) {
                        j = l;
                        }
                    }
            if (j >= 0) a.swap(i, j);
            i = j;
            } while (i >= 0);
            }
        
    };
    };

int main () {

    BinaryHeap a;

  
  
    return 0;
};
