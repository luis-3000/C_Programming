/* Passing Memory Addresses between functions, Bitwise Operators, Signed Integers, 
 * Shift Operators, Two's Compliment, Bit Masking. */


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
char * convertBase(unsigned int numberToConvert, int base, char *pConvertedNumber) 
{

	//All possible values to create all possible numeric bases to convert to (Base 2 - Base 16)
	char allValues[] = "0123456789abcdef";

	if (base < 2 || base > 16) {

		printf("Enter a Number Between  2 and 16\n");
		exit(1);
	}

	pConvertedNumber[32] = '\0';

	do {

		int value = numberToConvert % base;

		// move to the left of the character array
		pConvertedNumber = pConvertedNumber - 1;

		// store the appropriate value for the final converted value into the character array
		*pConvertedNumber = allValues[value];

		numberToConvert /= base;  // numberToConvert = numberToConvert / base;

	} while (numberToConvert != 0);

	return pConvertedNumber;
}

int main() {

	unsigned int numberSix = 6; // 110
	unsigned int numberSeven = 7;  //111

	char *pConvertedNumber;
	pConvertedNumber = malloc(33 * sizeof(char)); // 32 bit plus null character

	printf("Converted number %d to binary representation %s\n", numberSix, 
												convertBase(numberSix, 2, pConvertedNumber));

	// Bitwise operations
	unsigned int andSolution = numberSix & numberSeven;

	/// 110 & 111 = 110
	printf("%s & ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(andSolution, 2, pConvertedNumber));


	unsigned int orSolution = numberSix | numberSeven;

	/// 110 | 111 = 111
	printf("%s | ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(orSolution, 2, pConvertedNumber));


	unsigned int xOrSolution = numberSix ^ numberSeven;

	/// 110 ^ 111 = 001
	printf("%s ^ ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(xOrSolution, 2, pConvertedNumber));

	// Two's Complement to turn a number into its negative equivalent
	// Steps:
	// 1). Take the number and flip each bit
	// 2). Add 1 to it
	unsigned int onesComplementSolution = ~numberSix;
	printf("~%s = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s\n\n", convertBase(onesComplementSolution, 2, pConvertedNumber));
	printf("Negative of %d = %d\n\n", numberSix, (onesComplementSolution + 1));


	// Shift operations (<< and >>)
	unsigned int shiftLeftTwo = numberSix << 2;
	printf("%s << 2 = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = %d\n\n", convertBase(shiftLeftTwo, 2, pConvertedNumber), shiftLeftTwo);


	unsigned int shiftRightTwo = numberSix >> 2;
	printf("%s >> 2 = ", convertBase(numberSix, 2, pConvertedNumber));
	printf("%s = %d\n\n", convertBase(shiftRightTwo, 2, pConvertedNumber), shiftRightTwo);

	// Bit masking
	unsigned int analyzeMyBits = 170; // 10101010 
	unsigned int theMask = 15; // 00001111
	unsigned int last4Bits = analyzeMyBits & theMask;
	// 10101010
	// &
	// 00001111
	//---------
	// 00001010
	printf("Last 4 Bits : %s\n", convertBase(last4Bits, 2, pConvertedNumber));

	// Representing fractions in bonary
	// 						3  2  1  0
	// 0.625 * 2 = 1.25 ->  1
	//  .25 * 2 = 0.50 ->   1  0
	//  .50 * 2 = 1.00 ->   1  0  1
	//  .00 * 2 = 0 DONE

	// Does not work with Infinite Fractions
	// .1 * 2 = 0.2 (Binary .0)
	// .2 * 2 = 0.4 (Binary .00)
	// .4 * 2 = 0.8 (Binary .000)
	// .8 * 2 = 1.6 (Binary .0001)

	free(pConvertedNumber);

	return 0;
}