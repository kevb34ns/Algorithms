/** Basic, unoptimized n-Queens solver.
 *	 Takes 'n' as a command line argument.
 */

#include <iostream>
#include <cstdlib>

const int N_MAX = 64;

int absVal(int i)
{
	if (i < 0)
	{
		return -i;
	}
	else
	{
		return i;
	}
}

struct Queen
{
	int col;
	int row;

	Queen(int col, int row) : col(col), row(row)
	{

	}
};

struct Board
{
	int n;
	int* boardArray;

	Board(int n) : n(n)
	{
		boardArray = new int[n];
		for (int i = 0; i < n; ++i)
		{
			boardArray[i] = -1;
		}
	}

	// checks if the two objects specified by their column and row are in the same diagonal
	bool inDiagonal(int col1, int row1, int col2, int row2)
	{
		int colDiff = absVal(col1 - col2);
		int rowDiff = absVal(row1 - row2);
		return colDiff == rowDiff;
	}

	bool isUnderAttack(Queen* q)
	{
		for (int i = 0; i < q->col; i++)
		{
			// check column is not equal. Unnecessary, but included for the sake of completeness
			if (i == q->col)
			{
				return true;
			}

			if (boardArray[i] == q->row && q->row >= 0)
			{
				return true;
			}

			if (inDiagonal(i, boardArray[i], q->col, q->row))
			{
				return true;
			}
		}

		return false;
	}

	bool placeQueens(Queen* q)
	{
		if (q->col >= n)
		{
			delete q;
			return true;
		}

		bool isQueenPlaced = false;
		while (!isQueenPlaced && q->row < n)
		{
			if (isUnderAttack(q))
			{
				q->row += 1;
			}	
			else
			{
				boardArray[q->col] = q->row;
				Queen* newQ = new Queen(q->col + 1, 0);
				isQueenPlaced = placeQueens(newQ);

				if (!isQueenPlaced)
				{
					delete newQ;
					boardArray[q->col] = -1;
					q->row += 1;
				}		
			}
		}

		return isQueenPlaced;
	}

	void print(bool success)
	{
		if (success)
		{
			std::cout << "A placement was found:" << std::endl;
			for (int i = -1; i <= n; i++)
			{
				if (i == -1 || i == n)
				{
					for (int j = 0; j < n * 2 + 1; j++)
					{
						std::cout << "+";
					}
					std::cout << std::endl;
				}
				else
				{
					for (int j = -1; j < n; j++)
					{
						if (j == -1)
						{
							std::cout << "|";
						}
						else
						{
							if (boardArray[j] == i)
							{
								std::cout << "Q|";
							}
							else
							{
								std::cout << " |";
							}
						}
					}
					std::cout << std::endl;
				}
			}
		}
		else
		{
			std::cout << "Did not find placement" << std::endl;
		}
	}
};

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "USAGE: ./n-queens n" << std::endl;
		return -1;
	}

	int n = std::atoi(argv[1]);
	if (n > N_MAX)
	{
		n = N_MAX;
	}
	else if (n < 0)
	{
		n = 0;
	}

	Board board(n);

	bool success = board.placeQueens(new Queen(0, 0));
	board.print(success);

	return 0;
}