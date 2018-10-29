#include <vector>
#include <iostream>
#include <fstream>
#include "util.h"
using namespace std;

/* This function uses selection sort to sort a vector of ints and outputs to a file
 * The function also keeps track of the number of swaps it makes and writes it to
 * the same file
 */

void selectionSort (vector<int> nums, int size) {
	int minIndex, minValue;
	int swaps = 0;

	for (int start = 0; start < (size -1); start++) {
		minIndex = start;
		minValue = nums[start];
		for (int index = start+1; index < size; index ++) {
			if (nums[index] < minValue) {
				minValue = nums[index];
				minIndex = index;
			}
		}
		swap(nums[minIndex], nums[start]);
		swaps++;
	}
	//write the vector and # swaps to an output file
	ofstream outputFile;
	outputFile.open("SelectResults.txt", ios::app);
	outputFile << "Sorted array of size " << size << " sorted in " << swaps << " swaps \n";
	cout << "Sorted array of size " << size << " sorted in " << swaps << " swaps \n";
	for (int value : nums) {
		outputFile << value << " ";
		cout << value << " ";
	}
	outputFile << endl << endl;
	cout << endl << endl;
}

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
	cout << "Sorted array of size " << size << " sorted in " << swaps << " swaps \n";
	for (int value : nums) {
		outputFile << value << " ";
		cout << value << " ";
	}
	outputFile << endl << endl;
	cout << endl << endl;
}

void sortDriver () {
	bool exit = false;
	while ( exit == false) {
		cout << "Generating random data of size 1000\n";
		vector<int> numbers = genNums( 1000, true);
		cout << "They are:\n";
		for (int val : numbers) {
			cout << val << " ";
		}
		cout << endl;
		bubbleSort(numbers, 1000);
		selectionSort(numbers, 1000);
		cout << endl;
		exit = exitPrompt();
	}
}
