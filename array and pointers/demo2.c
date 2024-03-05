#include <stdio.h>
#include <stdlib.h>

int searchByKey(const int arr[], int size, int key) {
    for (int i = 0; i < size; i++) { 
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}
void insertByPosition(int arr[], int *size, int position, int value) {
    if (position < 0 || position > *size) {
        printf("Invalid position\n");
        return;
    }

    // Make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*size)++;
    printf("Element inserted successfully\n");
}

void deleteByPosition(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position\n");
        return;
    }

    // Shift elements to fill the gap
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element deleted successfully\n");
}

void insertByKey(int arr[], int *size, int key, int value) {
    int position = searchByKey(arr, *size, key);

    if (position == -1) {
        printf("Key not found\n");
    } else {
        insertByPosition(arr, size, position + 1, value);
        printf("Element inserted successfully\n");
    }
}

void deleteByKey(int arr[], int *size, int key) {
    int position = searchByKey(arr, *size, key);

    if (position == -1) {
        printf("Key not found\n");
    } else {
        deleteByPosition(arr, size, position);
        printf("Element deleted successfully\n");
    }
}

void insertByOrder(int arr[], int *size, int value) {
    int i = *size - 1;

    // Shift elements to find the correct position
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = value;
    (*size)++;
    printf("Element inserted successfully\n");
}

int searchByPosition(const int arr[], int size, int position) {
    if (position >= 0 && position < size) {
        return arr[position];
    } else {
        printf("Invalid position\n");
        return -1;
    }
}

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        // Swap elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move towards the center
        start++;
        end--;
    }

    printf("Array reversed successfully\n");
}

int main() {
    int size,i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);

    int choice;
    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert by position\n");
        printf("2. Delete by position\n");
        printf("3. Insert by key\n");
        printf("4. Delete by key\n");
        printf("5. Insert by order\n");
        printf("6. Search by key\n");
        printf("7. Search by position\n");
        printf("8. Reverse the contents\n");
        printf("9. Display array\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int position, value;
                printf("Enter position and value to insert: ");
                scanf("%d %d", &position, &value);
                insertByPosition(arr, &size, position, value);
                break;
            }
            case 2: {
                int position;
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteByPosition(arr, &size, position);
                break;
            }
            case 3: {
                int key, value;
                printf("Enter key and value to insert: ");
                scanf("%d %d", &key, &value);
                insertByKey(arr, &size, key, value);
                break;
            }
            case 4: {
                int key;
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(arr, &size, key);
                break;
            }
            case 5: {
                int value;
                printf("Enter value to insert by order: ");
                scanf("%d", &value);
                insertByOrder(arr, &size, value);
                break;
            }
            case 6: {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);
                int position = searchByKey(arr, size, key);
                if (position != -1) {
                    printf("Key found at position %d\n", position);
                } else {
                    printf("Key not found\n");
                }
                break;
            }
            case 7: {
                int position;
                printf("Enter position to search: ");
                scanf("%d", &position);
                int result = searchByPosition(arr, size, position);
                if (result != -1) {
                    printf("Element at position %d is %d\n", position, result);
                }
                break;
            }
            case 8:
                reverseArray(arr, size);
                break;
            case 9:
                printf("Array: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
        }
    } while (choice != 0);

    free(arr);
    return 0;
}
