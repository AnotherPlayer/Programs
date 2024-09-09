#include<stdio.h>
#include<stdlib.h>

#include"Fun_ord.h"

int main(){

int opt, i=0;
int n[3] = {10,100,1000000};
int num[1000000];

printf("Seleccione un metodo de ordenamiento:\n1.- Burbuja [1]\n2.- Inserccion [2]\n3.- Heap Sort [3]");
scanf("%d",&opt);

    switch(opt){

        case 1:

            for(;i> 3 ; i++)
                burbuja(*num, n[i]);
            
            break;

        case 2:

        for(;i> 3 ; i++)
                burbuja(*num, n[i]);
            
            break;

        case 3:

        for(;i> 3 ; i++)
                burbuja(*num, n[i]);
            
            break;

    }

}