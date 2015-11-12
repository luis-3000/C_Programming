/* Messing with Strings, Chars, Booleans, Functions & Pointers */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void noMoreNewline(char* theString) {
	
	char * isANewline;

	// return the last occurrence of what we are looking for (Here were are looking for '\n')
	isANewline = strrchr(theString, '\n');

	if (isANewline) {

		*isANewline = '\0';
	}
}

void makeLowercase(char* theString) {

	int i = 0;

	while (theString[i]) {
		theString[i] = tolower(theString[i]);
		i++;
	}
}

// void getCharInfo(){

// 	char theChar;

// 	while ((theChar = getChar()) != '\n') { //getChar undefined for x86_64 architecture?

// 		printf("Letter or Number %d\n\n", isalnum(theChar));

// 		printf("Alphabetic Char %d\n\n", isalpha(theChar));

// 		printf("Standard Blank %d\n\n", isblank(theChar));

// 		printf("Ctrl Char%d\n\n", iscntrl(theChar));

// 		printf("Number Char %d\n\n", isdigit(theChar));

// 		printf("Ahything but space %d\n\n", isgraph(theChar));

// 		printf("Lowercase %d\n\n", islower(theChar));

// 		printf("Uppercase %d\n\n", isupper(theChar));

// 		printf("Punctutation %d\n\n", ispunct(theChar));

// 		printf("Any space %d\n\n", isspace(theChar));
// 	}
// }

int main() {

	bool isANumber;
	int number;
	int sumOfNumbers = 0;

	// printf("Enter a number, or any other letter to display the sum of the numbers entered: ");

	// isANumber = (scanf("%d", &number) == 1);

	// while (isANumber) {
	// 	sumOfNumbers = sumOfNumbers + number; 
	// 	printf("Enter a number, or any other letter to display the sum of the numbers entered: ");
	// 	isANumber = (scanf("%d", &number) == 1);
	// }

	// printf("The sum is %d\n\n", sumOfNumbers);

	// char theChar;

	// while ((theChar = getChar()) != '~') { // Accepts a char when the 'enter' key is pressed
	// 	putchar(theChar);
	// }

	char name[50];

	printf("What is your name? ");

	//  Accepts a new character until the new line character ("enter key pressed") is entered.
	// Then, it replaces that new line character with the '\0' character, leaving the new string
	// in a single line of text. 
	// Problem is it can go beyond the allocated space for the new string 'name'. It does not
	// check the end of available storage.
	// The system reports a "warning: this progrom uses get(), which is unsafe" message
	// Some Operating Systems won't allow the usage of gets() it since it is unsafe, as my 
	// Mac OS X ignored it.
	gets(name);

	// Prints a string followed by the new line
	puts("Hi!");
	puts(name); 


	// fgets() is a better option which asks for the new string, the size and where the text is
	// coming from
	fgets(name, 50, stdin);
	fputs("Hello again! ", stdout);
	fputs(name, stdout);

	char * randomString = "Roses are red, violets are purple ... s";

	while (*randomString) {
		// print to screen a character at a time without a new line
		putchar(*randomString++);
	}

	// printing the long way (inneficient)
	int i = 0;
	while (randomString[i] != '\0') {
		putchar(randomString[i++]);  
	}

	char doYouWantToQuit[10];

	printf("Enter quit to quit: ");

	fgets(doYouWantToQuit, 10, stdin);

	noMoreNewline(doYouWantToQuit);

	// To make sure we handle upper case letters entered by user
	makeLowercase(doYouWantToQuit);

	printf(doYouWantToQuit);

	while (strcmp(doYouWantToQuit, "quit")) {

		printf("Enter quit to quit: ");

		fgets(doYouWantToQuit, 10, stdin);

		noMoreNewline(doYouWantToQuit);

		// To make sure we handle upper case letters entered by user
		makeLowercase(doYouWantToQuit);
	}

	printf("Thank you for typing: %s.\n\n", doYouWantToQuit);  

	getCharInfo();

	return 0;
}