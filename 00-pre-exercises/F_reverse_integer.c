// Roll No: CH.SC.U4CSE24041
// Name: Shaik Muzzammil
// Class: CSE-A, Amrita Vishwa Vidyapeetham, Chennai Campus
// Exercise: Pre-Exercise F - Reverse an Integer

#include <stdio.h>

int main(void) {
    long long num;
    printf("Enter an integer: ");
    if (scanf("%lld", &num) != 1) return 1;
    long long n = num, rev = 0;
    while (n != 0) {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    printf("Reversed = %lld\n", rev);
    return 0;
}
