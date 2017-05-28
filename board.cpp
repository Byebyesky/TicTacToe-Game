#include "board.h"
#include <iostream>

using namespace std;


void board::playGame()
{
	clearBoard();
	const char player1 = 'X';
	const char player2 = 'O';
	char currentPlayer = 'X';

	int x, y;
	int turn = 0;

	bool isDone = false;

	while (isDone == false)//main loop
	{

		printBoard();
		x = getXCoord();
		y = getYCoord();

		if (placeMarker(x, y, currentPlayer) == false)//checks if space is occupied
		{
			cout << "\nThis place is already taken!\n";
		} else 
		{
			turn++;
			if (victoryCheck(currentPlayer) == true)
			{
				printBoard();
				cout << "The game is over! Player " << currentPlayer << " won!\n" << endl;
				isDone = true;
			}
			else if (turn >= 9)
			{
				printBoard();
				cout << "It's a tie game!\n";
				isDone = true;
			}
			{

			}
			//Switch players.
			if (currentPlayer == player1)
			{
				currentPlayer = player2;
			}
			else
			{
				currentPlayer = player1;
			}

		}
	}
}


board::board()
{
	
	clearBoard();

}

void board::clearBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardrow[i][j] = ' '; //sets the whole board to spaces
		}
	}
}

void board::printBoard() //shows the board
{
	cout << endl;
	cout << "  |1 2 3|\n"; //top row
	for (int i = 0; i < 3; i++)
	{
		cout << "  -------\n";
		cout << i+1 << " |" << boardrow[i][0] << "|" << boardrow[i][1] << "|" << boardrow[i][2] << "|\n"; //outputs the field i = row
	}
	cout << "  -------\n";
}

int board::getXCoord() //While input is bad continue loop
{
	int x;
	bool isInputBad = true;
	while (isInputBad == true)
	{
		cout << "Enter the X coordinate: ";
		cin >> x;
		if (x < 1 || x > 3)
		{
			cout << "\nInvalid Coordinate!\n" << endl;
			cin.clear();
			while (cin.get() != '\n') 
			{
    			continue;
			}
		}
		else
			isInputBad = false;
	}
	return x-1;
}

int board::getYCoord()
{
	int y;
	bool isInputBad = true;
	while (isInputBad == true)
	{
		cout << "Enter the Y coordinate: ";
		cin >> y;
		if (y < 1 || y > 3)
		{
			cout << "\nInvalid Coordinate!\n" << endl;
			cin.clear();
			while (cin.get() != '\n') 
			{
    			continue;
			}
		}
		else
			isInputBad = false;
	}
	return y-1;
}

bool board::placeMarker(int x, int y, char currentPlayer)
{
	if (boardrow[y][x] != ' ') //checks if space is occupied
	{
		return false;
	}
	boardrow[y][x] = currentPlayer;//replaces the chosen field with the char
	return true;
}

bool board::victoryCheck(char currentPlayer)
{
	//check the rows
	for (int i = 0; i < 3; i++) {
		if ((boardrow[i][0] == currentPlayer) && (boardrow[i][0] == boardrow[i][1]) && (boardrow[i][1] == boardrow[i][2])) {
			return true;
		}
	}
		//check columns
		for (int i = 0; i < 3; i++) {
			if ((boardrow[0][i] == currentPlayer) && (boardrow[0][i] == boardrow[1][i]) && (boardrow[1][i] == boardrow[2][i])) {
				return true;
			}
		}
			//check diagonal left top > right bottom
			if ((boardrow[0][0] == currentPlayer) && (boardrow[0][0] == boardrow[1][1]) && (boardrow[1][1] == boardrow[2][2])){
				return true;
			}
			//check diagonal left bottom > right top
			if ((boardrow[2][0] == currentPlayer) && (boardrow[2][0] == boardrow[1][1]) && (boardrow[1][1] == boardrow[0][2])) {
				return true;
			}
			return false;
		

	
}