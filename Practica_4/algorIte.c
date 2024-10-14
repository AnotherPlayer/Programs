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