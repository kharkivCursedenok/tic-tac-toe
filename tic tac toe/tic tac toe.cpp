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
	for (int i = 0; i < 3; ++i) {
		if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) {
			std::cout << (player == 'X' ? "YOU WON!" : "YOU LOSE!");
			return true;
		}
	}

	for (int i = 0; i < 3; ++i) {
		if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
			std::cout << (player == 'X' ? "YOU WON!" : "YOU LOSE!");
			return true;
		}
	}

	if ((board[0] == player && board[4] == player && board[8] == player) ||
		(board[2] == player && board[4] == player && board[6] == player)) {
		std::cout << (player == 'X' ? "YOU WON!" : "YOU LOSE!");
		return true;
	}

	return false;
}
bool checkTie()
{
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			return false;
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
