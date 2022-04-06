#include <iostream>

using namespace std;

// 1. a gomoku board is a 2d array of chars, the size is 15x15
// 2. use a function to print the board
// 3. use a function to check if a move is valid
// 4. use a function to make a move

int gloval_pieces = 0;

void change_board(char board[15][15], int row, int col, char player)
{
	board[row][col] = player;
	gloval_pieces++;
}

bool isValid(char board[15][15], int row, int col)
{
	if (row < 0 || row > 14 || col < 0 || col > 14 || gloval_pieces == 225 || board[row][col] != '*')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void print_board(char board[15][15])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
}

bool is_win(char board[15][15], char player, int row, int col)
{
	if (gloval_pieces < 9)
	{
		return false;
	}
	char next = board[row][col];
	int count = -1; // enconter position twice

	int backward_flag = 1;
	// if backward is finished,
	// 1 = backward unfinished, -1 = forward unfinished
	// 0 = finished
	// check horizontal
	while (backward_flag != 0)
	{
		int next_row = row, next_col = col;
		if (next == player)
		{
			count++;
			if (count == 5)
			{
				return true;
			}
		}
		else
		{
			// check backward
			if (next_row > 0 && backward_flag == 1)
			{
				next = board[--next_row][next_col];
				if (next_row == 0)
				{
					backward_flag = -1;
					next_row = row;
				}
			}
			// check forward
			else if (next_row < 14 && backward_flag == -1)
			{
				next = board[++next_row][next_col];
			}
			// no 5 continuous pieces
			else
			{
				backward_flag = 0;
				count = -1;
			}
		}
	}

	// check vertical
	int vertical_flag = 1;
	while (vertical_flag != 0)
	{
		int next_row = row, next_col = col;
		if (next == player)
		{
			count++;
			if (count == 5)
			{
				return true;
			}
		}
		else
		{
			// check backward
			if (next_col > 0 && vertical_flag == 1)
			{
				next = board[next_row][--next_col];
				if (next_col == 0)
				{
					vertical_flag = -1;
					next_col = col;
				}
			}
			// check forward
			else if (next_col < 14 && vertical_flag == -1)
			{
				next = board[next_row][++next_col];
			}
			// no 5 continuous pieces
			else
			{
				vertical_flag = 0;
				count = -1;
			}
		}
	}

	// check diagonal
	int diagonal_flag = 1;
	while (diagonal_flag != 0)
	{
		int next_row = row, next_col = col;
		if (next == player)
		{
			count++;
			if (count == 5)
			{
				return true;
			}
		}
		else
		{
			// check backward
			if (next_row > 0 && next_col > 0 && diagonal_flag == 1)
			{
				next = board[--next_row][--next_col];
				if (next_row == 0 || next_col == 0)
				{
					diagonal_flag = -1;
					next_row = row;
					next_col = col;
				}
			}
			// check forward
			else if (next_row < 14 && next_col < 14 && diagonal_flag == -1)
			{
				next = board[++next_row][++next_col];
			}
			// no 5 continuous pieces
			else
			{
				diagonal_flag = 0;
				count = -1;
			}
		}
	}

	// check anti-diagonal
	int anti_diagonal_flag = 1;
	while (anti_diagonal_flag != 0)
	{
		int next_row = row, next_col = col;
		if (next == player)
		{
			count++;
			if (count == 5)
			{
				return true;
			}
		}
		else
		{
			// check backward
			if (next_row > 0 && next_col < 14 && anti_diagonal_flag == 1)
			{
				next = board[--next_row][++next_col];
				if (next_row == 0 || next_col == 14)
				{
					anti_diagonal_flag = -1;
					next_row = row;
					next_col = col;
				}
			}
			// check forward
			else if (next_row < 14 && next_col > 0 && anti_diagonal_flag == -1)
			{
				next = board[++next_row][--next_col];
			}
			// no 5 continuous pieces
			else
			{
				anti_diagonal_flag = 0;
				count = -1;
			}
		}
	}

	return false;
}

int machine_move(char board[15][15])
{
	char player = 'M';
	int row, col;
	do
	{
		row = rand() % 15;
		col = rand() % 15;
	} while (!isValid(board, row, col));

	change_board(board, row, col, player);
	if (is_win(board, player, row, col))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int human_move(char board[15][15])
{
	char player = 'H';
	int row, col;

Initial:
	print_board(board);
	cout << "Please enter a row and column to place your piece: ";
	cin >> row >> col;
	if (isValid(board, row, col))
	{
		change_board(board, row, col, player);
		if (is_win(board, player, row, col))
		{
			cout << "You win!" << endl;
			return 1;
		}
		else
		{
			int res = machine_move(board);
			if (res == 1)
			{
				cout << "You lose!" << endl;
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		cout << "Invalid move. Please try again." << endl;
		goto Initial;
	}
}

int main()
{
	char board[15][15];
	// initialize the board
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			board[i][j] = '*';
		}
	}

	print_board(board);
	int res = human_move(board);
	while (res == 0)
	{
		res = human_move(board);
	}
}
