// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise C - Sum of Values in Array

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, x;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }
    printf("Enter %d elements: ", n);
    long long sum = 0;
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum += x;
    }
    printf("Sum = %lld\n", sum);
    return 0;
}
