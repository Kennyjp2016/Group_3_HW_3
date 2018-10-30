#include <iostream>
#include "util.h"

const int LIONS = 4;
const int DAYS = 7;
const float MIN_FOOD = 0;
const float MAX_FOOD = 500;

void animalBusiness () {
	using namespace std;
	bool exit = false;
	while (exit == false) {
		int max = 0;
		int min = 501;
		cls();
		//create array of 4x7
		float lionFood[LIONS][DAYS];
		//init to all 0's for safety reasons
		for (int i = 0; i < LIONS; i++) {
			for (int j =0; j < DAYS; j++) {
				lionFood[i][j] = 0;
			}
		}
		//get food eaten by each lion
		for (int i = 0; i < LIONS; i++) {
			cout << "How man lb's did lion " << i + 1 << " eat on\n";
			for (int j = 0; j < DAYS; j++) {
				cout << "Day " << j + 1 << ": ";
				lionFood[i][j] = goodIn(MIN_FOOD, MAX_FOOD);
			}
			cls();
		}

		//find the average
		for (int i = 0; i < DAYS; i++) {
			float avg = 0;
			cout << "The average food eaten on day " << i+1 << " was: ";
			for (int j = 0; j < LIONS; j++) {
				avg = avg + lionFood[j][i];
			}
			avg = avg/DAYS;
			cout << avg << endl;
		}

		//find the min/max
		for (int i = 0; i < LIONS; i++) {
			for (int j = 0; j < DAYS; j++) {
				if (lionFood[i][j] < min) {
					min = lionFood[i][j];
				}
				if (lionFood[i][j] > max) {
					max = lionFood[i][j];
				}
			}
		}

		cout << "The least amount of food eaten was " << min << endl;
		cout << "The most amount of food eaten was " << max << endl;

		exit = exitPrompt();
	}
}
