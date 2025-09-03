#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int low, high;
    int state; 
} Frame;

// Merge function
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSortIterative(int arr[], int n) {
    Frame *stack = (Frame *)malloc(2 * n * sizeof(Frame));
    int top = -1;

    stack[++top] = (Frame){0, n - 1, 0};

    while (top >= 0) {
        Frame f = stack[top--];

        if (f.low < f.high) {
            if (f.state == 0) {
                int mid = (f.low + f.high) / 2;

                stack[++top] = (Frame){f.low, f.high, 1};

                stack[++top] = (Frame){mid + 1, f.high, 0};

                stack[++top] = (Frame){f.low, mid, 0};
            } else {
                int mid = (f.low + f.high) / 2;
                merge(arr, f.low, mid, f.high);
            }
        }
    }

    free(stack);
}

// Driver code
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSortIterative(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
