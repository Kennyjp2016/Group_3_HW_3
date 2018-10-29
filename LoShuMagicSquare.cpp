/* Lo Shu Magic Square */

#include <iostream>
#include <algorithm>
#include "util.h"
using namespace std;

/* define a test magic square matrix */
int MATRIX[3][3] = {
	{ 4, 9, 2},
	{ 3, 5, 7},
	{ 8, 1, 6}
};

/*
 * This function accepts a multi dimensional array of ints
 * The function displays it as a grid of numbers ex:
 *		 --- --- ---
 *		| 4 | 9 | 2 |
 *		 --- --- ---
 *		| 3 | 5 | 7 |
 *		 --- --- ---
 *		| 8 | 1 | 6 |
 *		 --- --- ---
 *
 *	Inputs
 *		int matrix	a 3 x 3 array
 *
 *	Outputs
 *
 */

void displayMatrix ( int matrix[3][3]) {
	for (int i = 0; i < 3; i++) {
		cout << "	 --- --- ---\n";
		cout << "	|";
		for (int j = 0; j < 3; j++) {
			cout << " " << matrix[i][j] << " |";
		}
		cout << endl;
	}
	cout << "	 --- --- ---\n";
}


/* This function determines if a 3 x 3 array of ints contains all the numbers 1-9
 *
 *	Inputs
 *		int matrix	a 3 x 3 array of intigers
 *
 *	Returns
 *		true	all the numbers from 1-9 are present && they are the only numbers
 *		false	not all of the numbers from 1-9 are present || there is a number from
 *				outside the range
 */
bool goodSquare (int matrix[3][3]) {
	int range[9];
	//init range to all 0's
	for (int i = 0; i < 9; i++) {
		range[i] = 0;
	}

	for (int i = 0; i < 3; i++) {
		for (int j =0; j < 3; j++) {
			//if any number in the matrix is outside the range return false
			if (matrix[i][j] < 1 || matrix[i][j] > 9) {
				cout << "Bad Square\n";
				return false;
			} else {
				range[matrix[i][j]-1] = +1;
			}
		}
	}


	for (int i = 0; i < 9; i++) {
		if (range[i] < 1){
			return false;
		}
	}

	//if no issues found return true
	return true;
}


/*
 * This function checks to see if a 3 x 3 matrix is a magic square
 * a grid of integers is a magic square IFF each int is unique (1 - 9)
 * and each column row and diagonal sums up to the same number
 *
 *	Inputs
 *		int matrix	a 3 x 3 array of integers
 *
 *	Outputs
 *		true	returned if each row/col/diag sum to the same number
 *		false	returned if the array is not magic
 */
bool isMagic (int matrix[3][3]) {

	//check the sum of first row
	int testSum = 0;
	for (int i = 0; i < 3; i++) {
		testSum += matrix[0][i];
	}
	//compare the sum of the other rows against the first result
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += matrix[i][j];
		}
		if (sum != testSum) {
			return false;
		}
	}
	//compare against the columns
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += matrix[j][i];
		}
		if (sum != testSum) {
			return false;
		}
	}
	//compare against the diagonals
	if (matrix[0][0] + matrix[1][1] + matrix[2][2] != testSum) {
		return false;
	}
	if (matrix[2][0] + matrix[1][1] + matrix[0][2] != testSum) {
		return false;
	}
	return true;
}


void magicSquareDriver () {
	bool exit = false;
	while (exit == false) {
		cls();
		//generate a matrix of numbers between 1 and 9 (inclusive)
		int matrix[3][3];
		//create an array of nums from 1 - 9
		int array[9];
		for (int i = 0; i < 9; i++) {
			array[i] = i + 1;
		}
		//shuffle the array randomly
		random_shuffle(begin(array), end(array));

		//assign nums from array to matrix according to their position
		for (int i =0; i < 9; i++) {
			matrix[i/3][i%3] = array[i];
		}

		cout << "The square:\n";
		displayMatrix(matrix);
		if (goodSquare(matrix) == true) {
			if (isMagic(matrix) == true) {
				cout << "Is a Magic Square\n\n";
			} else {
				cout << "Is not magic\n\n";
			}
		} else {
			cout << "Does not contain all the numbers from 1 - 9\n\n";
		}
		exit = exitPrompt();
	}
}
