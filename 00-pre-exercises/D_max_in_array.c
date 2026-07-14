// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise D - Find Maximum Number in Array

#include <stdio.h>
#include <limits.h>

int main(void) {
    int N, i;
    printf("Enter number of elements: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Array size must be > 0\n");
        return 1;
    }
    printf("Enter %d elements: ", N);
    int max = INT_MIN, x;
    for (i = 0; i < N; ++i) {
        scanf("%d", &x);
        if (x > max) max = x;
    }
    printf("Maximum = %d\n", max);
    return 0;
}
