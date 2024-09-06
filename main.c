#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    for (int j = 0; j < size - 1; j++) {
        int minIndex = j;
        for (int i = j + 1; i < size; i++) {
            // Compare elements and print comparison
            printf("C %d %d\n", minIndex, i);
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        if (minIndex != j) {
            // Swap elements and print swap operation
            int temp = arr[j];
            arr[j] = arr[minIndex];
            arr[minIndex] = temp;
            printf("T %d %d\n", j, minIndex);
        }
    }
}

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    int swapped; 
    int lastSwap;
    int end = size - 1;

    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        lastSwap = 0;

        for (int j = 0; j < end; j++) {
            // Compare adjacent elements and print comparison
            printf("C %d %d\n", j, j + 1);
            if (arr[j] > arr[j + 1]) {
                // Swap elements and print swap operation
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printf("T %d %d\n", j, j + 1);
                swapped = 1;
                lastSwap = j + 1;
            }
        }

        if (swapped == 0) {
            break; // No swaps, array is sorted
        }

        end = lastSwap - 1; // Update the end point for optimization
    }
}

int main() {
    char algorithm[10];
    int size;

    // Read the sorting algorithm name and the number of elements
    scanf("%s %d", algorithm, &size);

    // Allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Error: memory allocation\n");
        return 1;
    }

    // Read the array elements
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Select the sorting algorithm based on input
    if (strcmp(algorithm, "selection") == 0) {
        selectionSort(arr, size);
    } else if (strcmp(algorithm, "bubble") == 0) {
        bubbleSort(arr, size);
    }

    // Display the sorted list
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    return 0;
}
