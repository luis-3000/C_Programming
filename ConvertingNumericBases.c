/*  Converting between numeric bases */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> // for the pow()
#include <ctype.h> // To help detect if an alpha character was received


/* Converting from other Bases to Base 10.
 * Parameters: 
 * 1). The number to convert in String form (as a Character array)
 * 2). The Original Base of that number.
 * 3). The number of numbers in that Char Array representing the number to convert */
int baseToDecimal(char * number, int baseFrom, int sizeOfNumber) {

	int result = 0;
	int toThePowerOf = 0;  //8^0, 8^1, ...

	// Loop that starts at the highest exponent point of the array and decrements down
	for (int i = (sizeOfNumber) - 2; i >=0; --i) {
				// because of index 0 and to avoid '\0'

		// Copy the style ... 455 base 8 = (4*8^2() + (5*8^1) + (5*8^0) = 301 base 10
		// For each number in the array:
		// Get the Original Base ^ Increasing Exponent
		// Multiply the Char array numbers TIMES the previous number calculated	
		// Add the result to other results

		// check if an alpha  character was received
		if(isalpha(number[i])) {

			// convert to lowercase and subtract the value of 'a' 97-10 = 87 (10 ->numbers 0-9) 
			int charCode = ((int)tolower(number[i])) - 87; //

			result += charCode * pow(baseFrom, toThePowerOf);			
		
		} else {  // Evertying else that is not a letter

			result += (number[i] - '0') * pow(baseFrom, toThePowerOf);

		}

		toThePowerOf++;
	}

	printf("%s in the base %d equals %d in base 10\n", number, baseFrom, result);

	return result;

}




/* Converting from Base 10 to Base 2, 8 and 16  */
char * convertBase(unsigned int numberToConvert, int base) {

	// working with bytes, 32 bits plus the null character
	char buffer[33];
	char *pConvertedNumber;

	//All possible values to create all possible numeric bases to convert to (Base 2 - Base 16)
	char allValues[] = "0123456789abcdef";

	if (base < 2 || base > 16) {

		printf("Enter a Number Between  2 and 16\n");
		exit(1);
	}

	// Point to the last index in the character array to store the null character
	pConvertedNumber = &buffer[sizeof(buffer)-1];

	*pConvertedNumber = '\0';

	do {

		int value = numberToConvert % base;

		// move to the left of the character array
		pConvertedNumber = pConvertedNumber - 1;

		// store the appropriate value for the final converted value into the character array
		*pConvertedNumber = allValues[value];

		numberToConvert /= base;  // numberToConvert = numberToConvert / base;

	} while (numberToConvert != 0);

	printf("%s", pConvertedNumber);

	return pConvertedNumber;

}

int main() {

	unsigned int numberOne = 60;  // In Binary is 111100
	printf("%d in Base 2 = ", numberOne);
	convertBase(numberOne, 2);
	printf("\n");

	printf("%d in Base 8 = ", numberOne);
	convertBase(numberOne, 8);
	printf("\n");

	printf("%d in Base 16 = ", numberOne);
	convertBase(numberOne, 16);
	printf("\n");

	//Converting from base 8 to base 10
	char numberToConvert[] = "74";

	baseToDecimal(numberToConvert, 8, sizeof(numberToConvert));

	// Converting from base 16 to base 10
	char numberToConvertB16[] = "3C";

	baseToDecimal(numberToConvertB16, 16, sizeof(numberToConvertB16));

	return 0;
}