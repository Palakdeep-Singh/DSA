#include <stdio.h>
#include <stdlib.h>

// Function to sort array by frequency of elements
void sortByFrequency(int *arr, int n) {
    // Create a frequency array... hihest possible range 100 and also give 0 value to all the indexes.using calloc
    int *freq = (int *)calloc(100, sizeof(int));
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Create a temporary array to store sorted elements
    int *sorted = (int *)malloc(n * sizeof(int));
    int index = 0;

    // Sort elements by frequency (least frequent first)
    for (int count = 1; count <= n; count++) {
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] == count) {
                sorted[index++] = arr[i];
            }
        }
    }

    // Print the sorted array
    printf("Sorted array by frequency:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // Free allocated memory
    free(freq);
    free(sorted);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sortByFrequency(arr, n);

    free(arr);
    return 0;
}
