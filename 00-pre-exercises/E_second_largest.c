// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise E - Find Second Largest Number in Array

#include <stdio.h>
#include <limits.h>

int main(void) {
    int n;
    printf("Enter number of elements (>= 2): ");
    if (scanf("%d", &n) != 1 || n < 2) {
        printf("Need at least two elements\n");
        return 1;
    }
    printf("Enter %d elements: ", n);
    int largest = INT_MIN, second = INT_MIN, x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x > largest) { second = largest; largest = x; }
        else if (x > second && x < largest) second = x;
    }
    if (second == INT_MIN) printf("No second largest (all equal?)\n");
    else printf("Second largest = %d\n", second);
    return 0;
}
