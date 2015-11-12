// Pointers

#include <stdio.h>

void pointerRandomNumbers(int* randx, int* randy) {

	*randx = rand() % 50 + 1;
	*randy = rand() % 50 + 1;

	printf("New randx in function = %d\n\n", *randx);
	printf("New randy in function = %d\n\n", *randy);
}

void editMessageSent(char* message, int size) {
	
	char newMessage[] = "new Message";

	if (size > sizeof(newMessage)) {

		for (int i = 0; i < sizeof(newMessage); i++) {
			message[i] = newMessage[i];
		}
	} else {
		printf("New Message is too big\n\n");	
	}

}

int main(){

	// When you compile and run your program you are provided
	// with a piece of memory in ram to store data like
	// variables.

	int rand1 = 12, rand2 = 15;
	
	// Each time you create an int 4 bytes of data are saved 
	// and that part of memory has an address you can use
	// to locate the data.
	
	// You can return that address by placing a & before 
	// the variable name in c.
	
	printf("rand1 = %p : rand2 = %p\n\n", &rand1, &rand2);
	
	// Sometimes these variables are stored next to each other 
	// and at other times that isn't true
	
	printf("Size of int %d\n\n", sizeof(int));
	
	// To assign the address to another variable proceed it with
	// an asterisk * 
	
	int * pRand1 = &rand1;
	
	// If we use %p we get the hexadecimal version of the address
	
	printf("Pointer %p\n\n", pRand1);	
	
	// If we use %d we get the decimal version of the address
	
	printf("Value %d\n\n", pRand1);
	
	// We have to use the * to get the value stored there
	// This is known as dereferencing the pointer
	// Dereferencing means to use the pointer to access the variable
	
	printf("Value %d\n\n", *pRand1);

	int randx = 0, randy = 0;
	
	printf("Main before function call\n\n");

	printf("randx = %d\n\n", randx);
	printf("randy = %d\n\n", randy);

	pointerRandomNumbers(&randx, &randy);

	printf("Main After function call\n\n");

	printf("randx = %d\n\n", randx);
	printf("randy = %d\n\n", randh);
	
	// ARRAYS AND POINTERS
	
	// An array name is pretty much a pointer
	
	int primeNumbers[] = {2,3,5,7};
	
	// We can print the values by index
	
	printf("First index : %d\n\n", 
		primeNumbers[0]);
		
	// You can print the first value also with *
	
	printf("First index with * : %d\n\n", 
		*primeNumbers);
	
	// You can use pointer arithmetic to access the other values
	// with *
	// This is in essence adding 1 to the address and since
	// it contains ints it jumps 4 bytes forward
	// Yes you can use it to get other data stored in memory
	
	printf("Second index with * : %d\n\n", 
		*(primeNumbers + 1));
		
	// ARRAYS OF STRINGS
	
	// To create an array of strings, you have to create an
	// array of pointers
	
	char * students[4] = {"Sally", "Mark", "Paul", "Sue"};
	
	// You can retrieve them now like any other data in an array
	
	for(int i = 0; i < 4; i++){
	
		printf("%s : %d\n\n", students[i], &students[i]);
	
	}

	char randommessage[] = "Edit my message";

	printf("Old Message: %s \n\n", randomMessage);

	editMessageSent(randomMessage, sizeof(randomMessage));

	printf("New Message: %s \n\n", randomMessage);


	return (0);
}