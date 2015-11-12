/*  Text File I/O  */
#include <stdio.h>
#include <stdlib.h>



int main() {

	// CREATING A FILE AND WRITING TO IT

	int randomNumber;

	// Pointer to a file
	FILE *pFile;

			// If the file wasn't opened it returns a 1, otherwise a 0
	pFile = fopen("randomnumbers.txt", "w"); //"w" - open a file and if it doesn't exist, create it

	//a - append
	//a+ - open or create a text file, then append anything we decide to add, to the end of 
	//    anything already in the file
	//r+ - read
	//w+ - write

	printf("!pFile : %d\n", !pFile);

	if (!pFile) { // If unable to open the file

		printf("Error: Cound't Write fo file");

		return 1; // Exit out with error 1 from main()
	}

	// If we get to this point, it means we were able to open the file
	for (int i = 0; i <10; i++) {

		randomNumber = rand() % 100;

		// prints whatever is supplied to a file
		fprintf(pFile, "%d\n", randomNumber);

	}

	printf("Success writing to file.\n");

	//Close the file
	if (fclose(pFile) != 0) { // Check if file was successfully closed

		printf("Error: File Not Closed!\n");

	}

	// READING A FILE

	char buffer[1000]; // Expecting only 1000 character per line as max

	FILE *pFile2;

	pFile2 = fopen("randomnumbers.txt", "r");


	if (!pFile2) { // If unable to open the file

		printf("Error: Cound't Write fo file");

		return 1;
	}

	// read up to 1000 characters per line
	while (fgets(buffer, 1000, pFile2) != NULL) {

		printf("%s", buffer);
	}

	// Another way to print the information is
	while (fscanf(pFile2, "%s", buffer) == 1) {

		puts(buffer); // prints the string plus a new line 
	}

	printf("Success reading from file.\n");

	//Close the file
	if (fclose(pFile2) != 0) { // Check if file was successfully closed

		printf("Error: File Not Closed!\n");

	}		


	// READING AND WRITING FROM/TO A FILE

	char buffer2[1000];

	FILE *pFile3;

	pFile3 = fopen("randomwords.txt", "r+");

	if (!pFile3) { // If unable to open the file

		printf("Error: Cound't Write fo file");

		return 1;
	}

	fputs("Messing With Strings", pFile3);

	fseek(pFile3, 12, SEEK_SET); // Reading cursor ends up at the end of the file

	//SEEK_SET - Start from the beginning of the File
	//SEEK_CUR - Move based off of current position in the file
	//SEEK_END - Move based off of starting at end of the file

	fputs(" Files ", pFile3);

	//Re-set reading cursor to beginning of file in order to read the words in the file
	fseek(pFile3, 0, SEEK_SET);

	fseek(pFile3, 0, SEEK_END);
	

	// Get the number of bytes read
	long numberOfBytes = ftell(pFile3);

	printf("Number of Bytes in File : %ld\n", numberOfBytes);

	// Go back to the beginning of the file 
	fseek(pFile3, -20, SEEK_CUR);

	printf("Success Reading From File \n");

	while (fgets(buffer2, 1000, pFile3) != NULL) {

		printf("%s\n", buffer2);
	}


	return 0;
}