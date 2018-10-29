/* ==============================================================================
 *	This file is the main file for Group 3's assignment 3
 *	due 8/30/18
 *
 *	James Conory
 * ============================================================================*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "questions.h"
#include "util.h"
using namespace std;

int main() {
	//get the system time for rand calls
	srand(time(NULL));
	bool exit = false;
	int select;
	while (exit == false) {
		//clear the window
		cls();
		cout << "This is Group 3's Assignment 1\n";
		cout << "\t1 Display Matrix\n";
		cout << "\n\n";
		cout << "Enter your selection: ";
		select = goodIn(0, 1);

		switch (select) {
			case 1:
				magicSquareDriver();
				break;
			case 2:
				;
				break;
			case 3:
				;
				break;
			case 4:
				;
				break;
			case 0:
				;
				break;
			default:
				cout << "That input didn't work.\n";
				cout << "Please input the number by your selection";
				break;
		}
	}
	return 0;
}
