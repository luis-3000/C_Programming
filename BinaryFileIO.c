/*  Binary File I/O & Error Handling in C. */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

	// WRITING TEXT TO A BINARY FILE

	FILE *pFile; // file pointer

	char * buffer; // to read what was written to the file

	// size_t is a  datatype used to represents the size of an element in bytes.
	// For example 10 characters would be equal to size_t of 11, that's the number of bytes
	// to represent those characters in bytes
	size_t dataInFile;

	long fileSize;

	pFile = fopen("names.bin", "rb+"); // rb - read data in bytes

	if (pFile == NULL) { // If file doesn't exist

		perror("Error Occurred");
		printf("Error code: %d\n", errno); // throw an error


		printf("File Being Created\n\n");

		// create the file
		pFile = fopen("names.bin", "wb+");

		// Check if file was successfully created
		if (pFile == NULL) { 

			perror("Error Occurred");
			printf("Error Code: %d\n", errno);
			exit(1);
		}
	}

	char name[] = "To be or not to be, that is the question!"; // 'name' is already a pointer
															  // to an array of chars
	// To write binary data to a file.
	// Parameters:
	// 1. Pass a pointer to what we want to write to the file, 'name' already is a pointer
	// 2. Size of each element in the 'array' (or 'struct' if working with structs) 
	// 3. Number of elements we're planning to write to the file (Given by # of 
	//         elements divided by an individual element.)
	// 4. The pointer to the file we're writing to
	fwrite(name, sizeof(name[0]), sizeof(name)/sizeof(name[0]), pFile);

	// Move to the enf of the file we've written to, in order to be able to calculate its size
	fseek(pFile, 0, SEEK_END);

	// Now get the size of the file
	fileSize = ftell(pFile);

	// rewind back to the beginning of the file, in order to read its contents
	rewind(pFile);

	// Create a buffer to hold our file in order to print its contents
	buffer = (char *) malloc(sizeof(char)*fileSize); // allocate enough memory

	if (buffer == NULL) { // If empty file

		perror("Error Occurred");
		printf("Error Code: %d\n", errno);
		exit(2);		

	}

	// Read info from our file into our new buffer
	//Params: buffer, # of bytes taken up by each element passed in, # of elements, file reading from
	dataInFile = fread(buffer, 1, fileSize, pFile);

	if (dataInFile != fileSize) { // Error check we got the correct file size compared to 
								  // the size written to the file.
		perror("Error Occurred");
		printf("Error Code: %d\n", errno);
		exit(3);		

	}

	// Otherwise, we know we got our information
	printf("\nPrinting the information contained in the file:\n");
	printf("%s\n", buffer);
	printf("\n");

	// Close file
	fclose(pFile);

	// free up memory
	free(buffer);



	//  CREATING AND WRITING AN ARRAY TO A FILE, THEN READING ANY ELEMENT FROM INSIDE THE
	// FILE TO PRINT IT TO SCREEN 

	FILE *pFile2;

	pFile2 = fopen("randomnums.bin", "wb+");

	if (pFile2 == NULL) { // If file does not exist

		perror("Error Occurred");
		printf("Error code: %d\n", errno);


		printf("File Being Created\n\n");

		pFile2 = fopen("randomnums.bin", "rb+");

		if (pFile2 == NULL) {

			perror("Error Occurred");
			printf("Error Code: %d\n", errno);
			exit(4);
		}
	}

	int randomNumbers[20];

	// Generate random numbers
	for (int i = 0; i < 20; i++) {
		randomNumbers[i] = rand() % 100;
		printf("Number %d is %d\n", i, randomNumbers[i]);
	} 

	// write them to file
	fwrite(randomNumbers, sizeof(int), 20, pFile2);

	long randomIndexNumber;
	int numberAtIndex;

	printf("Which Random Number do you Want? ");

	scanf("%ld", &randomIndexNumber);

	// Put the reading cursor at the index position of the number asked for.
	// In Binary mode, the offset (second parameter) must the the index of the number
	// we're looking for TIMES the possible size in bytes
	// SEEK_SET - to look for the specified index
	fseek(pFile2, (randomIndexNumber * sizeof(int)), SEEK_SET);

	// Read next number from the file after we've moved the cursor to the right position.
	fread(&numberAtIndex, sizeof(int), 1, pFile2);

	printf("The Random Number at Index %ld is %d\n", randomIndexNumber, numberAtIndex);

	fclose(pFile2);


	return 0;
}