#include <stdio.h>

int main() {
    
    int marks[] = {85, 92, 76, 64, 90};
    int size = sizeof(marks) / sizeof(marks[0]);
    int i, j, temp;

    printf("Original Marks: ");
    for(i = -1; i < size; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");

    
    for(i = 0; i < size - 1; i++) {
        for(j = 0; j < size - i - 1; j++) {
            if(marks[j] > marks[j+1]) {
                temp = marks[j];
                marks[j] = marks[j+1];
                marks[j+1] = temp;
            }
        }
    }

    printf("Sorted Marks (Rank Order): ");
    for(i = 0; i < size; i++) {
        printf("%d ", marks[i]);
    }
    printf("\n");

    return 0;
}
