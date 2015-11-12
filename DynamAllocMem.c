/*  Dynamically allocating memory with malloc() */
#include <stdio.h>
#include <stdlib.h>

struct product {

	float price;
	char productName[30];

};

int main() {

	int amtOfNumbersToStore;

	printf("How many numbers do you want to store? : ");
	
	scanf("%d", &amtOfNumbersToStore);
	
	int * pRandomNumbers; // Pointer to memory that will be allocated for these numbers
	
	printf("Allocating memory for those numbers ... \n\n");
	pRandomNumbers = (int *) malloc(amtOfNumbersToStore * sizeof(int)); //(* int) not needed in C
																	    //but needed in C++

	if (pRandomNumbers != NULL) { // If memory was properly allocated by the system
	
		int i = 0;
	
		printf("Enter a Number or Quit: ");

		//while we haven't exceeded the amount of numbers to enter && a digit was entered
		while (i < amtOfNumbersToStore && scanf("%d", &pRandomNumbers[i]) == 1) { 
	
			printf("Enter a number or Quit: ");

			i++;
		}

		printf("\n\nYou entered the following numbers:\n");

		for (int j = 0; j < i; j++) {
			printf("%d\n", pRandomNumbers[j]);
		}
	}

	free(pRandomNumbers); // Not really needed since all objects no longer used are EVENTUALLY
						  // returned to memory but it's a good practice to free memory as soon
						  // as it is no longer needed like at this point in this program

	// DYNAMICALLY ALLOCATING MEMORY, AND STORING STRUCTS INSIDE OF SUCH MEMORY
	// ------------------------------------------------------------------------

	struct product *pProducts;

	int i, j;

	int numberOfProducts;

	printf("\nEnterthe Number of Products to Store: "); 

	scanf("%d", &numberOfProducts);

	pProducts = (struct product *) malloc(numberOfProducts * sizeof(struct product));

	for (i = 0; i < numberOfProducts; i++) {

		printf("Enter a Product Name: ");

		scanf("%s", &(pProducts+i)->productName); // pointer arithmetic

		printf("Enter a Product Price: ");

		scanf("%f", &(pProducts+i)->price);
	}

	printf("\nProducts stored:\n");

	for (j = 0; j < numberOfProducts; ++j) {
		printf("%s\t%.2f\n", (pProducts+j)->productName, (pProducts+j)->price);
	}


	// Make sure to free memory
	free(pProducts);
	return 0;
}