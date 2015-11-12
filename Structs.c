/* Structs */

#include <stdio.h>

// structs are used when you need more then one 
// piece of data to describe one thing.
// We can't use an array because arrays only hold one
// type of data.
struct dogsFavs {
	char *food;
	char *friend;
};

// This creates a dog struct with the data needed
typedef struct dog {  // using typedef

	// Labeled with const because they won't change
	const char* name;
	const char *breed;
	int avgHeightCm;
	int avgWeightLbs;

	//struct within a struct
	struct dogsFavs favoriteThings;

} dog;


void getDogInfo(struct dog theDog) {
	printf("\n");

	// Since a struct is initialized like an array we
	// may think we can access the data like this theDog[0],
	// but they don't work that way. We need to use the
	// dot operator like this.
	printf("Name: %s\n\n", theDog.name);
	printf("Breed: %s\n\n", theDog.breed);
	printf("Avg Height: %d cms\n\n", theDog.avgHeightCm);
	printf("Avg Weight: %d lbs\n\n", theDog.avgWeightLbs);
}

void getMemoryLocations(struct dog theDog){
	printf("Name Location: %d\n\n", theDog.name);
	printf("Breed Location: %d\n\n", theDog.breed);
	printf("Height Location: %d\n\n", theDog.avgHeightCm); // & used since these aren't pointers
	printf("Weight Location: %d\n\n", theDog.avgWeightLbs);
}

void getDogsFavs(dog theDog){
	printf("\n");

	printf("%s loves %s and his frind is %s\n\n",
		theDog.name, 
		theDog.favoriteThings.food,
		theDog.favoriteThings.friend);
}

/* Passing data to a function. */
void setDogWeightPtr(dog *theDog, int newWeight) {
	(*theDog).avgWeightLbs = newWeight; // (*theDog) means, "yes, we want to reference theDog struct"
									    // so that we can change its data

	printf("The weight was changed to %d\n\n", (*theDog).avgWeightLbs);

	// Same thing but using -> notation
	printf("The weight was changed to %d\n\n", theDog->avgWeightLbs);	// -> Means "access the
																		// variable avgWeightLbs
 																		// in the struct 'theDog'. "
}

int main() {
	
	// Define a new dog by passing the values specific to this dog.
	// struct is the data type and cujo is the variable name
	struct dog cujo = {"Cujo", "Saint Bernard", 90, 264};

	// Now we can pass all the dog info easily
	getDogInfo(cujo);

	// A struct defines a template for your data type
	// A struct variable defines the memory needed to fit the data
	
	// What happens if a struct is copied to another?
	// They point to the same memory locations
	struct dog cujo2 = cujo;

	getMemoryLocations(cujo);

	getMemoryLocations(cujo2);

	//struct within a struct
	dog benji = {"Benji", "Silky Terrier", 25,9, {"Meat", "Joe Camp"}};

	getDogsFavs(benji);

	// Passing data to a function
	setDogWeightPtr(&benji, 11);

	printf("The Weight in Main() %d\n\n", benji.avgWeightLbs);

	return 0;
}