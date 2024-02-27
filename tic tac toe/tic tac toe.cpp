#include <ctime>
#include <iostream>
using namespace std;

char board[9]{ ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

void showBoard()
{
	cout << endl;
	cout << "       |       |       " << endl;
	cout << "   " << board[0] << "   |    " << board[1] << "  |  " << board[2] << endl;
	cout << "       |       |       " << endl;
	cout << "_______________________" << endl;
	cout << "       |       |       " << endl;
	cout << "   " << board[3] << "   |    " << board[4] << "  |  " << board[5] << endl;
	cout << "       |       |       " << endl;
	cout << "_______________________" << endl;
	cout << "       |       |       " << endl;
	cout << "   " << board[6] << "   |    " << board[7] << "  |  " << board[8] << endl;
	cout << "       |       |       " << endl;
	cout << endl;
}
void playerMove (const char player)
{
	int number = 0;
	cout << "Pick a slot! (1-9)" << endl;
	cin >> number;
	number--;

	while (true) {
		if (board[number] != ' ')
		{
			cout << "Wrong move, try again!" << endl;
			cin >> number;
			number--;
		}
		else
		{
			board[number] = player;
			break;
		}
	}
}
void computerMove (const char computer)
{
	int number;
	srand(time(0));

	while (true) {
		number = rand() % 9;
		if (board[number] == ' ')
		{
			board[number] = computer;
			break;
		}
	}
}
bool checkWin (const char player)
{
	if (board[0] != ' ' && board[0] == board[1] && board[1] == board[2])
	{
		board[0] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	} else if (board[3] != ' ' && board[3] == board[4] && board[4] == board[5])
	{
		board[3] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	}
	else if (board[6] != ' ' && board[6] == board[7] && board[7] == board[8])
	{
		board[6] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	}
	else if (board[1] != ' ' && board[1] == board[4] && board[4] == board[7])
	{
		board[1] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	}
	else if (board[0] != ' ' && board[0] == board[3] && board[3] == board[6])
	{
		board[0] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	}
	else if (board[2] != ' ' && board[2] == board[5] && board[5] == board[8])
	{
		board[2] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	}
	else if (board[0] != ' ' && board[0] == board[4] && board[4] == board[8])
	{
		board[0] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	}
	else if (board[2] != ' ' && board[2] == board[4] && board[4] == board[6])
	{
		board[2] == player ? cout << "YOU WON!" : cout << "YOU LOSE!";
	} else
	{
		return false;
	}
	return true;
}
bool checkTie()
{
	for (int i = 0; i < 9; i++)
	{
		if(board[i] == ' ')
		{
			return false;
			break;
		}
	} 
	cout << "It`s a tie!" << endl;
	return true;
}

int main() 
{
	char computer = 'O';
	char player = 'X';
	bool running = true;
	showBoard();
	while (running) 
	{
		
		playerMove(player);
		if (checkWin(player)) {
			running = 0;
			break;
		}
		else if (checkTie())
		{
			running = 0;
			break;
		}

		computerMove(computer);
		
		if (checkWin(player)) {
			running = 0;
			break;
		} else if (checkTie())
			{
				running = 0;
				break;
			}
		showBoard();
	}
	cout << endl;
	showBoard();
	cout << "Thanks for playing the game!" << endl;
	return 0;
}
