#include <stdio.h>

/* Function to sort an array using insertion sort */
void insertion_sort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i]; // Element to be inserted into the sorted portion
        j = i - 1;

        // Move elements of a[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key; // Insert key into its correct position
    }
}

/* Function to print the array */
void printArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {12, 31, 25, 8, 32, 17};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sorting array elements are - \n");
    printArr(a, n);

    insertion_sort(a, n);

    printf("After sorting array elements are - \n");
    printArr(a, n);

    return 0;
}
