#pragma once


class board
{
public:
	board();
	void playGame();
	

private:
	void clearBoard();
	void printBoard();
	int getXCoord();
	int	getYCoord();
	bool victoryCheck(char currentPlayer);
	bool placeMarker(int x, int y, char currentPlayer);
	char boardrow[3][3];

};

