#include <vector>
#include <iostream>
#include <fstream>
#include "util.h"
using namespace std;

/* This function sorts a vector or ints and writes the output to a file
 * The function also keeps track of the number of exchanges made and writes that
 * to the same file
 */
void bubbleSort (vector<int> nums, int size) {
	int maxElement;
	int swaps = 0;
	//sort the vectors
	for (maxElement = size -1; maxElement > 0; maxElement--) {
		for (int i = 0; i < maxElement; i++) {
			if (nums[i] > nums[i + 1]) {
				swap(nums[i], nums[i + 1]);
				swaps++;
			}
		}
	}
	//write the vector and # swaps to an output file
	ofstream outputFile;
	outputFile.open("BubbleResults.txt", ios::app);
	outputFile << "Sorted array of size " << size << " sorted in " << swaps << " swaps \n";
	for (int value : nums) {
		outputFile << value << " ";
	}
}

void sortDriver () {
	bool exit = false;
	while ( exit == false) {
		cout << "Generating random data of size 10\n";
		vector<int> numbers = genNums( 10, true);
		cout << "They are:\n";
		for (int val : numbers) {
			cout << val << " ";
		}
		bubbleSort(numbers, 10);
		cout << endl;
		exit = exitPrompt();
	}
}
