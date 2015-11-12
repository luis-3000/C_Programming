/* Working with Struct Linked Lists */
#include <stdio.h>
#include <stdlib.h>

struct product {

	char productName[30]; // Assuming it won't take more than this for a product's name
	float price;

	struct product *next; // reference to the next struct in the linked list

};

// Pointers to first and last elements in the linked list
struct product *pFirstNode = NULL;
struct product *pLastNode = NULL;

void createNewList() {

	// Create a new struct for a new element
								// Allocating memory for each new struct
	struct product *pNewStruct = (struct product *) malloc(sizeof(struct product));
									// Cast not needed for C, but makes it clearer
									// what is going on here. (C++ requires it)	
	pNewStruct->next = NULL;

	printf("Enter Product Name: ");
	scanf("%s", &(pNewStruct)->productName);

	printf("Enter Product price: ");
	scanf("%f", &(pNewStruct)->price);

	pFirstNode = pLastNode = pNewStruct;
}

void inputData() {

	// Special case, trying to insert a node which turns out to be the first new element 
	// in the list
	if (pFirstNode == NULL) {

		createNewList();

	} else { // This means we are inserting the second or third element in the list

		// Create a new struct for a new element
									 // Allocating memory for each new struct
		struct product *pNewStruct = (struct product *) malloc (sizeof(struct product)); 
									// Cast not needed for C, but makes it clearer
									// what is going on here. (C++ requires it)

		printf("Enter Product Name: ");
		scanf("%s", &(pNewStruct)->productName);


		printf("Enter Product price: ");
		scanf("%f", &(pNewStruct)->price);

		// Check if this is going to be the second item in the list
		if (pFirstNode == pLastNode) { // This means we only have one node in the list
			
			pFirstNode->next = pNewStruct;

			pLastNode = pNewStruct;

			pNewStruct->next = NULL;

		} else { // General case for the third and more subsequent new nodes

			pLastNode->next = pNewStruct;

			pNewStruct->next = NULL;

			pLastNode = pNewStruct;
		}

	}
}


void outputData() {

	struct product *pProducts = pFirstNode; // Create a new node to step through the list,
											// make it point to the head of the list.

	printf("\nProducts Entered:\n");

	while (pProducts != NULL)  {

		printf("%s costs %.2f\n\n", pProducts->productName, pProducts->price);

		pProducts = pProducts->next;
	}
}

// Global variable
struct product *pProductBeforeProductToDelete = NULL;

/* Searches for an specified product and returns a pointer to the struct for such product. */
struct product* searchForProduct(char * productName) {

	struct product *pProductIterator = pFirstNode; // The name sort of reflects the purpose

	while (pProductIterator != NULL) {

							// Returns 0 if they are equal, otherwise it returns another number
		int areTheyEqual = strncmp(pProductIterator->productName, productName, 30); 

		if (!areTheyEqual) { // If 0, (if the strings are equal, we found the product)

			printf("%s was found and it costs %.2f\n\n",
												pProductIterator->productName,
															pProductIterator->price);

			return pProductIterator; // return a reference to the product found (its node)
		}

		pProductBeforeProductToDelete = pProductIterator; //Best place to assign this value here

		// Otherwise, keep moving the reference to the next node to seek out the product in the list
		pProductIterator = pProductIterator->next;
	}

	// Reached the end of the list. we did not find a match for the product we were looking for
	printf("%s wasn't found!\n\n", productName);

	return NULL; // The product we wanted was not found in the list, NULL returned as default
}

/* Removes a product given the name of such product. */
void removeProduct(char * productName) {

	struct product *pProductToDelete = NULL;

	pProductToDelete = searchForProduct(productName);

	if (pProductToDelete != NULL) { // product to delete was found

		printf("%s  Was Deleted\n\n", productName);

		if (pProductToDelete == pFirstNode) { // If deleting what turned out to be the first element

			pFirstNode = pProductToDelete->next; // remove it from the list by moving this reference
		
		} else {  // By keeping a reference to the product before the one we're deleting
				  // we can delete the reference to it.
				  // This variable was designated a value inside searchForProduct()
			pProductBeforeProductToDelete->next = pProductToDelete->next;

		}

		free(pProductToDelete);

	} else {

		printf("%s was not found!", productName); // Product not found
	}
}

int main() {

	inputData();
	inputData();
	inputData();

	outputData();

	printf("Searching for product ... \n");
	searchForProduct("Tomato");

	printf("Removing a product ...\n");
	removeProduct("Tomato");

	printf("The remaining products are: \n");
	outputData();

	return 0;
}