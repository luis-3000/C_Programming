/*  Structs, Unions, Enums, Linked Lists and Recursive Structures. */

#include <stdio.h>

typedef struct product {
	
	const char *name;
	float price;

	struct product *next; // Pointer to next element of a linkedlist

} product;

void printLinkedList(product *pProduct) {

	while (pProduct != NULL) {

		printf("\tA %s costs %.2f\n\n", (*pProduct).name, pProduct->price);

		pProduct = pProduct->next;
	}

}

int main() {

	// A Union can have different types of data declared at the same time BUT it can
	// only hold 1 type of value at a time.
	// Sometimes a Union can be a 'short' and sometimes it can be a 'float' but never
	// both at the same time.
	typedef union {

		short individual;
		float pound;
		float ounce;


	} amount;

	// adding values to a union
	amount orangeAmt = {.ounce = 16};

	orangeAmt.individual = 4;

	printf("\nOrange Juice Amount:  %.2f : Size: %d\n\n", 
			orangeAmt.ounce, 
			sizeof(orangeAmt.ounce));

	printf("Number of Oranges:  %d : Size: %d\n\n", 
				orangeAmt.individual, 
				sizeof(orangeAmt.individual));

	orangeAmt.pound = 1.5;

	printf("Orange Juice Amount:  %.2f : Size: %d\n\n", 
			orangeAmt.pound, 
			sizeof(orangeAmt.pound));

	// Using a Union inside of a Struct
	typedef struct {
		char *brand;
		amount theAmount;
	} orangeProduct;

	orangeProduct productOrdered = {"Chiquita",
									.theAmount.ounce = 16 };

	printf("Youg bought %.2f ounces of %s oranges\n\n", 
			productOrdered.theAmount.ounce,
			productOrdered.brand);

	// Enumerated types
	typedef enum {
		INDIV,
		OUNCE,
		POUND
	} quantity;

	quantity quantityType = INDIV;

	orangeAmt.individual = 4;

	if (quantityType == INDIV) {
		printf("You bought %d oranges\n\n", orangeAmt.individual);
	} else if (quantityType == OUNCE) {
		printf("You bought %.2f ounces of oranges\n\n", orangeAmt.ounce);
	} else {
		printf("You bought %.2f pounds of oranges\n", orangeAmt.pound);
	}

	// Using linked lists and structs

	// we create the individual objects representing each link (product)
	product tomato = {"Tomato", .51, NULL};
	product potato = {"Potato", 1.21, NULL};
	product lemon = {"Lemon", 1.69, NULL};
	product milk = {"Milk", 3.09, NULL};
	product turkey = {"Turkey", 1.86, NULL};
	

	// Create the linkedlist with the items instantiated above (This can also be done in a method)
	tomato.next = &potato; // We make sure to assign it the address of the next element
	potato.next = &lemon;
	lemon.next = &milk;
	milk.next = &turkey;

	// Now, we decide to create a new product
	product apple = {"Apple", 1.58, NULL};

	// and INSERT it to the list, on the second-to last position
	lemon.next = &apple;
	apple.next = &milk;

	printf("Printing the linked list of products: \n\n");
	printLinkedList(&tomato); // pass the head of the list as a reference



	return 0;
}