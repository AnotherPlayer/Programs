#include<stdio.h>
#include<stdlib.h>
#include <math.h> 
#include <limits.h> 

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



//TORRES DE HAOI

// A structure to represent a stack 
struct Stack 
{ 
unsigned capacity; 
int top; 
int *array; 
}; 

// function to create a stack of given capacity. 
struct Stack* createStack(unsigned capacity) 
{ 
	struct Stack* stack = 
		(struct Stack*) malloc(sizeof(struct Stack)); 
	stack -> capacity = capacity; 
	stack -> top = -1; 
	stack -> array = 
		(int*) malloc(stack -> capacity * sizeof(int)); 
	return stack; 
} 

// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
return (stack->top == stack->capacity - 1); 
} 

// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
return (stack->top == -1); 
} 


void push(struct Stack *stack, int item) 
{ 
	if (isFull(stack)) 
		return; 
	stack -> array[++stack -> top] = item; 
} 

// Function to remove an item from stack. It 
// decreases top by 1 
int pop(struct Stack* stack) 
{ 
	if (isEmpty(stack)) 
		return INT_MIN; 
	return stack -> array[stack -> top--]; 
} 

//Function to show the movement of disks 
void moveDisk(char fromPeg, char toPeg, int disk) 
{ 
	printf("Move the disk %d from \'%c\' to \'%c\'\n", 
		disk, fromPeg, toPeg); 
}

// Function to implement legal movement between 
// two poles 
void moveDisksBetweenTwoPoles(struct Stack *src, 
			struct Stack *dest, char s, char d) 
{ 
	int pole1TopDisk = pop(src); 
	int pole2TopDisk = pop(dest); 

	// When pole 1 is empty 
	if (pole1TopDisk == INT_MIN) 
	{ 
		push(src, pole2TopDisk); 
		moveDisk(d, s, pole2TopDisk); 
	} 

	// When pole2 pole is empty 
	else if (pole2TopDisk == INT_MIN) 
	{ 
		push(dest, pole1TopDisk); 
		moveDisk(s, d, pole1TopDisk); 
	} 

	// When top disk of pole1 > top disk of pole2 
	else if (pole1TopDisk > pole2TopDisk) 
	{ 
		push(src, pole1TopDisk); 
		push(src, pole2TopDisk); 
		moveDisk(d, s, pole2TopDisk); 
	} 

	// When top disk of pole1 < top disk of pole2 
	else
	{ 
		push(dest, pole2TopDisk); 
		push(dest, pole1TopDisk); 
		moveDisk(s, d, pole1TopDisk); 
	} 
} 

//Function to implement TOH puzzle 
void tohIterative(int num_of_disks, struct Stack 
			*src, struct Stack *aux, 
			struct Stack *dest) 
{ 
	int i, total_num_of_moves; 
	char s = 'S', d = 'D', a = 'A'; 

	//If number of disks is even, then interchange 
	//destination pole and auxiliary pole 
	if (num_of_disks % 2 == 0) 
	{ 
		char temp = d; 
		d = a; 
		a = temp; 
	} 
	total_num_of_moves = pow(2, num_of_disks) - 1; 

	//Larger disks will be pushed first 
	for (i = num_of_disks; i >= 1; i--) 
		push(src, i); 

	for (i = 1; i <= total_num_of_moves; i++) 
	{ 
		if (i % 3 == 1) 
		moveDisksBetweenTwoPoles(src, dest, s, d); 

		else if (i % 3 == 2) 
		moveDisksBetweenTwoPoles(src, aux, s, a); 

		else if (i % 3 == 0) 
		moveDisksBetweenTwoPoles(aux, dest, a, d); 
	} 
} 


