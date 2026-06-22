#include <stdio.h>
void display(int arr[], int size);
int insertEnd(int arr[], int size, int element);
int insertByPosition(int arr[], int size, int element, int pos);
int deleteByValue(int arr[], int size, int element);
int deleteByPosition(int arr[], int size, int pos);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, pos, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        printf("Element %d: ", i);
        scanf("%d", &arr[i]);
    }
    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Element (at the end)\n");
        printf("3. Insert Element by Position\n");
        printf("4. Delete Element (by value)\n");
        printf("5. Delete Element by Position\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, size);
                break;
	    
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                size = insertEnd(arr, size, element);
                break;

            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position/index (0 to %d): ", size);
                scanf("%d", &pos);
                size = insertByPosition(arr, size, element, pos);
                break;

            case 4:
                if (size == 0) {
                    printf("Array is empty! Nothing to delete.\n");
                } else {
                    printf("Enter the value to delete: ");
                    scanf("%d", &element);
                    size = deleteByValue(arr, size, element);
                }
                break;

            case 5:
                if (size == 0) {
                    printf("Array is empty! Nothing to delete.\n");
                } else {
                    printf("Enter the position/index to delete (0 to %d): ", size - 1);
                    scanf("%d", &pos);
                    size = deleteByPosition(arr, size, pos);
                }
                break;

            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}
void display(int arr[], int size) {
    if (size == 0) {
        printf("The array is currently empty.\n");
        return;
    }
    printf("Current Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insertEnd(int arr[], int size, int element) {
    if (size >= MAX_SIZE) {
        printf("Error: Array Overflow! Cannot insert.\n");
        return size;
    }
    arr[size] = element;
    printf("'%d' inserted at the end.\n", element);
    return size + 1; 
}
int insertByPosition(int arr[], int size, int element, int pos) {
    if (size >= MAX_SIZE) {
        printf("Error: Array Overflow! Cannot insert.\n");
        return size;
    }
    if (pos < 0 || pos > size) {
        printf("Invalid position! Out of bounds.\n");
        return size;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    printf("'%d' inserted at index %d.\n", element, pos);
    return size + 1;
}


int deleteByValue(int arr[], int size, int element) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("'%d' not found in the array.\n", element);
        return size;
    }
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("First occurrence of '%d' deleted.\n", element);
    return size - 1;
}
int deleteByPosition(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Invalid position! Out of bounds.\n");
        return size;
    }
    int removed = arr[pos];
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Element '%d' at index %d deleted.\n", removed, pos);
    return size - 1;
}
