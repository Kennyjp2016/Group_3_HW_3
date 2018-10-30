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
	cout << "Linear Search Results\n";
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

int binarySearch(const vector<int> array, int numElems, int value) {
	int first = 0,
		last = numElems - 1,
		middle,
		position = -1,
		comps = 0;
	bool found = false;

	while (!found && first <= last) {
		middle = (first + last) /2;
		if (array[middle] == value) {
			found = true;
			position = middle;
		}
		else if (array[middle] > value)
			last = middle -1;
		else
			first = middle + 1;
		comps++;
	}
	ofstream outfile;
	outfile.open("binaryResults.txt", ios::app);
	cout << "Binary Search Results\n";
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
		binarySearch(numbers, size, value);
		exit = exitPrompt();
	}
}
