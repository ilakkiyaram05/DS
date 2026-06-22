#include <stdio.h>
#include <limits.h>

void findSecondHighest(int arr[], int size) {

    if (size < 2) {
        printf("Invalid Input! Array must have at least two elements.\n");
        return;
    }
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
       }
    }


    if(second == INT_MIN)
    {
       printf("There is no 2nd highest salary


    if (second == INT_MIN) {
        printf("There is no second highest salary).\n");
    } else {
        printf("Second Highest Salary: %d\n", second);
    }
}
int main() {
    int salaries[] = {25000, 30000, 45000, 40000};
    int size = sizeof(salaries) / sizeof(salaries[0]);

    printf("Input: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", salaries[i]);
    }
    printf("\nOutput: ");
    
    findSecondHighest(salaries, size);

    return 0;
}
