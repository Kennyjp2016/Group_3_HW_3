#include <iostream>
using namespace std;

char gameboard[9] = { '*', '*', '*', '*', '*', '*', '*', '*', '*' };

void dispGameboard() {
	int count;
	count = 0;
	cout << "\tA\tB\tC";
	while (count < 9) {
		if (count == 0) { cout << "\n" << '1'; }
		else if (count == 3) { cout << "\n" << '2'; }
		else if (count == 6) { cout << "\n" << '3'; }
		cout << "\t" << gameboard[count];
		count++;
	}
}

int LocationCalculation(int row, char column) {
	int choice;
	if ((row == 1) && (column == 'a')) choice = 0;
	else if ((row == 1) && (column == 'b')) choice = 1;
	else if ((row == 1) && (column == 'c')) choice = 2;
	else if ((row == 2) && (column == 'a')) choice = 3;
	else if ((row == 2) && (column == 'b')) choice = 4;
	else if ((row == 2) && (column == 'c')) choice = 5;
	else if ((row == 3) && (column == 'a')) choice = 6;
	else if ((row == 3) && (column == 'b')) choice = 7;
	else if ((row == 3) && (column == 'c')) choice = 8;
	return choice;
}

int player1GetInput() {
	int choice, row;
	char column;
	dispGameboard();
	cout << '\n' << "Player 1\n" << "Where would you like to go? Please type Row, then enter, then column, then enter. " << endl;
	cin >> row >> column;

	choice = LocationCalculation(row, column);

	return choice;
}

int player2GetInput() {
	int choice, row;
	char column;
	dispGameboard();
	cout << "\n" << "Player 2\n" << "Where would you like to go? Please type Row, then enter, then column, then enter. " << endl;
	cin >> row >> column;

	choice = LocationCalculation(row, column);

	return choice;
}

void checkWinner() {

}
void TicTacToe(){
	int count = 0;
	int player1move, player2move;
	while (count < 5) {

		player1move = player1GetInput();

		while (gameboard[player1move] != '*') { 
			cout << "Please use a location that has not been used yet" << endl; 
			player1move = player1GetInput(); }

		gameboard[player1move] = 'X';

		player2move = player2GetInput();

		while (gameboard[player2move] != '*') { 
			cout << "Please use a location that has not been used yet" << endl;
			player2move = player2GetInput(); }

		gameboard[player2move] = 'O';
	}
}
