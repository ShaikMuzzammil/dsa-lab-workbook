// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise B - Sum of N Natural Numbers

#include <stdio.h>

int main(void) {
    int N;
    long long sum = 0;
    printf("Enter a positive integer N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    // Arithmetic formula: 1 + 2 + ... + N = N*(N+1)/2
    sum = (long long)N * (N + 1) / 2;
    printf("Sum of first %d natural numbers is: %lld\n", N, sum);
    return 0;
}
