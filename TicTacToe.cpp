#include <iostream>
#include <vector>
#include "util.h"
using namespace std;

vector<vector<char>> gameboard;

void dispGameboard( vector<vector<char>> matrix) {
	cls();
	cout << "\t  1   2   3\n";
	for (int i = 0; i < 3; i++) {
		cout << "\t --- --- ---\n";
		cout << i + 1 << "\t|";
		for (int j = 0; j < 3; j++) {
			cout << " " << matrix [i][j] << " |";
		}
		cout << endl;
	}
	cout << "\t --- --- ---\n";
}

bool isEmpty (int row, int col) {
	if (gameboard[row][col] == '*') {
		return true;
	} else {
		cout << "That space is occupied. Please select a different space\n";
		return false;
	}
}

void playerMove (bool player) {
	int row, col;
	char p_symbol;
	bool canPlace = false;
	if (player) {
		p_symbol = 'X';
	} else {
		p_symbol = 'O';
	}
	cout << "Player " << player + 1 << " enter the space you want to claim\n";
	while (canPlace == false) {
		cout << "Row:\t";
		row = goodIn(1, 3);
		cout << "Column:\t";
		col = goodIn(1, 3);
		row--;
		col--;
		canPlace = isEmpty(row, col);
	}
	gameboard[row][col] = p_symbol;
}

/* This function iterates through all the rows/col/diag and checks to see if
 * any are filled with nothing but X's or O's
 * If any are victory is declared for the player who's symbol matches
 */

bool checkVictory () {
	//check the rows
	for (int i = 0; i < 3; i++) {
		if (gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2]) {
			if (gameboard[i][0] == 'O') {
				cout << "Player 1 is Victorious !!!\n";
				return true;
			}
			if (gameboard[i][0] == 'X') {
				cout << " Player 2 is Victorious !!!\n";
				return true;
			}
		}
	}
	//check the columns
	for (int i = 0; i < 3; i++) {
		if (gameboard[0][i] == gameboard[1][i] && gameboard[0][i] == gameboard[2][i]) {
			if (gameboard[i][0] == 'O') {
				cout << "Player 1 is Victorious !!!\n";
				return true;
			}
			if (gameboard[i][0] == 'X') {
				cout << "Player 2 is Victorious !!!\n";
				return true;
			}
		}
	}
	//compare the diagonals
	if (gameboard[1][1] != '*') {
		if (gameboard[0][0] == gameboard[1][1] && gameboard[0][0] == gameboard[2][2]) {
			if (gameboard[2][2] == 'O') {
				cout << "Player 1 is Victorious !!!\n";
			} else {
				cout << "Player 2 is Victorious !!!\n";
			}
			return true;
		}
		if (gameboard[2][0] == gameboard[1][1] && gameboard[2][0] == gameboard[0][2]) {
			if (gameboard[2][2] == 'O') {
				cout << "Player 1 is Victorious !!!\n";
			} else {
				cout << "Player 2 is Victorious !!!\n";
			}
			return true;
		}
	}
	return false;
}

/* This function return true if none of the values in gameboard are = to a *
 * this is in case of a tie
 */
bool isTie () {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameboard[i][j] == '*') {
				return false;
			}
		}
	}
	return true;
}
void TicTacToe(){
	bool victory = false;
	bool player = 1;
	bool exit = false;
	while (exit == false) {
		//set up the board
		gameboard.clear();
		gameboard = {
			{ '*', '*', '*'},
			{ '*', '*', '*'},
			{ '*', '*', '*'}
		};
		bool victory = false;
		bool player = 0;
		while (victory == false) {
			dispGameboard( gameboard );
			playerMove(player);
			dispGameboard( gameboard );
			victory = checkVictory();
			//switch the player
			if (player == 0) {
				player = 1;
			} else {
				player = 0;
			}
			if (isTie() == true) {
				cout << "A strange game. The only winning move is not to play. How about a nice game of chess?\n";
				break;
			}
		}
		exit = exitPrompt();
	}
}
