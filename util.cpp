/* ==============================================================================
 * This file is for storing utility functions that don't fit anywere else.
 * Each function is preceded with a contract that describes it's purpose,
 * inputs and outputs.
 *
 * The functions should be prototyped in util.h
 *
 *  ===========================================================================*/

#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
using namespace std;

/* Int input validation
 * This function accepts two integers that form a range, accepts an input using
 * cin, and tests whether that input is an integer in that range. The function
 * will keep asking until an input is accepted.
 *
 * Important. The function does not prompt the user for input the first time.
 * You should prompt the user for input when you call the function;
 *
 *	Inputs
 *		int min		the minimum acceptable value
 *		int max		the maximum acceptable value
 *
 *	Outputs
 *		int value	an int value between the max and min
 */

int goodIn (int min, int max) {
	int value = 0;
	if (min >= max || max <= min) {
		cout << "Some one messed up and the range should be checked";
		return value;
	}
	cin >> value;
	while (min > value || max < value || cin.fail()) {
		if (cin.fail()) {
			cout << "Please enter an integer\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> value;
		}
		if (value < min || value > max) {
			cout << "Please enter a number between " << min;
			cout << " and " << max << '\n';
			cin >> value;
		}
	}
	return value;
}

float goodIn ( float min, float max) {
	float value;
	if (min >= max || max <= min) {
		cout << "Some one messed up and the range should be checked";
		return value;
	}
	cin >> value;
	while (min > value || max < value || cin.fail()) {
		if (cin.fail()) {
			cout << "Please enter an integer\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> value;
		}
		if (value < min || value > max) {
			cout << "Please enter a number between " << min;
			cout << " and " << max << '\n';
			cin >> value;
		}
	}
	return value;
}


/*
 * This function clears the terminal screen
 * It soes it differently depending on weither or not you are on windows or linux
 * TODO improve how the screen is cleared on windows
 */

#ifdef _WIN32
#include <stdlib.h>
void cls() {
	system("cls");
}
#endif
#ifdef __gnu_linux__
void cls() {
	cout <<"\033[H\033[2J";
	return;
}
#endif

/* This function prompts the user to enter 1 or 0 
 * and returns true or false respectivly.
 * This is used to determin weither or not the user wants to 
 * return to the main menu
 */

bool exitPrompt () {
	int exit;
	cout << "\nEnter 1 to stay.\nEnter 2 to return to the main menu\n";
	exit = goodIn(1, 2);
	if (exit == 2) {
		return true;
	} else if (exit == 1) {
		return false;
	}
	return false;
}

/*
 * This function creates a vector of numbers that are either random or sequential
 *
 * Inputs
 *	int size	The size of the vector to create
 *	bool random	This is true if the ve3ctors should be filled with a random number
 *
 * Outputs
 *	vector<int> nums	a vector of ints that are either random or sequential depending
 *						on the value of random
 */

vector<int> genNums (int size, bool random) {
	vector<int> nums(size);
	for(int i; i < size; i++) {
		nums[i] = i;
	}
	if (random == true) {
		random_shuffle(begin(nums), end(nums));
	}
	return nums;
}
