// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise G - Array Operations (Insert, Delete, Search, Display)

#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX], size = 0, choice, element, pos, i;

    printf("=== Array ADT Menu ===\n");
    printf("1. Insert  2. Delete  3. Search  4. Display  5. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }
        if (choice == 1) {
            printf("Enter element and position: ");
            scanf("%d %d", &element, &pos);
            if (pos < 0 || pos > size) { printf("Invalid position\n"); continue; }
            if (size >= MAX)            { printf("Full\n"); continue; }
            for (i = size; i > pos; --i) arr[i] = arr[i-1];
            arr[pos] = element;
            ++size;
            printf("Inserted\n");
        } else if (choice == 2) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            if (pos < 0 || pos >= size) { printf("Invalid\n"); continue; }
            for (i = pos; i < size-1; ++i) arr[i] = arr[i+1];
            --size;
            printf("Deleted\n");
        } else if (choice == 3) {
            printf("Enter element to search: ");
            scanf("%d", &element);
            int found = -1;
            for (i = 0; i < size; ++i) if (arr[i] == element) { found = i; break; }
            if (found >= 0) printf("Found at %d\n", found);
            else            printf("Not found\n");
        } else if (choice == 4) {
            if (size == 0) printf("Empty\n");
            else {
                for (i = 0; i < size; ++i) printf("%d ", arr[i]);
                printf("\n");
            }
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
