// 筑波大学院入試過去問平成23年度2月期

#include <stdio.h>
#include <math.h>

void swap(int *x, int *y);
void shift_up(int a[], int n);
void shift_down(int a[], int i, int size);
void sort2(int a[], int n);

int main() {
    int n = 12;
    int i;
    int a[] = {3, 1, 5, 9, 7, 2, 6, 8, 0, 4, 2, 4};

    printf("＜ソート前＞\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] : %d\n", i, a[i]);
    }

    sort2(a, n);

    printf("＜ソート後＞\n");
    for (i = 0; i < n; i++) {
        printf("a[%d] : %d\n", i, a[i]);
    }
}

void sort2(int a[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        shift_up(a, n - i - 1);
    }

    for (i = 0; i < n; i++) {
        swap(&a[0], &a[n - i - 1]);
        shift_down(a, 0, n - i - 1);
    }
}

void swap(int *x, int *y) {
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

void shift_up(int a[], int n) {
    int parent;

    if (n == 0) {
        return;
    } else {
        parent = ceil((float)n / 2) - 1;
        // parent = (n - 1) / 2;

        if (a[parent] < a[n] || a[parent] == a[n]) {
            return;
        } else {
            swap(&a[parent], &a[n]);
            shift_up(a, parent);
        }
    }
}

void shift_down(int a[], int i, int size) {
    int left = i * 2 + 1, right = i * 2 + 2;
    int smallest = i;
    if (right < size && a[right] < a[smallest]) {
        smallest = right;
    }
    if (left < size && a[left] < a[smallest]) {
        smallest = left;
    }
    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        shift_down(a, smallest, size);
    }
}

