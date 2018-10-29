#include <iostream>
#include <vector>
#include <fstream>
#include "util.h"
using namespace std;

int linearSearch (const vector<int> arr, int size, int value) {
	int index = 0;
	int position = -1;
	bool found = false;
	int comps = 0;
	while (index < size && !found) {
		if (arr[index] == value) {
			found = true;
			position = index;
		}
		index++;
		comps++;
	}
	ofstream outfile;
	outfile.open("linearResults.txt", ios::app);
	if (position == -1) {
		cout << "The value was not found\n";
		outfile << "The value was not found\n";
	} else {
		cout << "The number was found at position " << position << "\n";
		outfile << "The number was found at position " << position << "\n";
	}
	cout << "It took " << comps << " comparisions to find\n";
	outfile << "It took " << comps << " comparisions to find\n";
	return position;
}

void searchBenchDriver () {
	bool exit = false;
	while (exit == false) {
		cls();
		cout << "Enter the size of the array you want to searhc through: ";
		int size;
		size = goodIn(1, 1000);
		vector<int> numbers = genNums (size, false);
		cout << "What Number are you searching for: ";
		int value = goodIn(0 -size, size * 2);
		cout << endl;
		linearSearch(numbers, size, value);
		exit = exitPrompt();
	}
}
