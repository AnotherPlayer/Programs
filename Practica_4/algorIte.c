#include<stdio.h>
#include<stdlib.h>

void factorialIte(int n){

    int x=1,i;

    if(n==0 || n==1)
        x=1;
    
    else{
        for(i=1 ; i<=n ; i++)
            x*=i;
    }

    printf("Factorial %d: %d\n",n,x);

}

// Function to print fibonacci series
void printFib(int n) {
    if (n < 1) {
        printf("Invalid Number of terms\n");
        return;
    }

    // When number of terms is greater than 0
    int prev1 = 1;
    int prev2 = 0;

    printf("%d ", prev2);

    // If n is 1, then we do not need to
    // proceed further
    if (n == 1)
        return;

    printf("%d ", prev1);

    // Print 3rd number onwards using
    // the recursive formula
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        printf("%d ", curr);
    }
}
