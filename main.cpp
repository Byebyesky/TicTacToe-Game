#include <iostream>
#include <string>
#include "board.h"


using namespace std;

int main()
{
	char input;
	bool isDone = false;
	board game;
	while (isDone == false)
	{
		game.playGame();		
		cout << "Do you want to play again?" << endl;
		cout << "Press N to quit or any key to play again: ";
		cin >> input;
		if (input == 'N' || input == 'n')
		{
			isDone = true;
		}
		cin.clear();
		while (cin.get() != '\n') 
		{
    		continue;
		}
	}
	return 0;
}