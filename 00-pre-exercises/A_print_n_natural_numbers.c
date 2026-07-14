// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise A - Print N Natural Numbers

#include <stdio.h>

int main(void) {
    int N;
    printf("Enter a positive integer N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Please enter a positive integer greater than 0.\n");
        return 1;
    }
    for (int i = 1; i <= N; ++i) printf("%d ", i);
    printf("\n");
    return 0;
}
