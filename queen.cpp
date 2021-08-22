#include <iostream>
#include <cstring>

#define N 4

bool isCorrectPlace(char board[][N], int r, int c)
{
	for (int i = 0; i < r; i++)
		if (board[i][c] == 'Q')
			return false;

	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (board[i][j] == 'Q')
			return false;

	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (board[i][j] == 'Q')
			return false;

	return true;
}

void rec_queen(char board[][N], int r, int  * compt)
{
	if (r == N)
	{
        *(compt)+=1;
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++)
				std::cout << board[i][j] << " ";
			std::cout << '\n';
		}
		std::cout << '\n';
		
		return;
	}

	for (int i = 0; i < N; i++) 
	{
		if (isCorrectPlace(board, r, i)) 
		{
			board[r][i] = 'Q';

			rec_queen(board, r + 1, compt);
		}
        board[r][i] = '0';
	}
}

int main()
{
	char board[N][N];
	memset(board, '0', sizeof (board));
    int compt = 0;
	rec_queen(board, 0, &compt);
    std::cout << "Number of solution is: " << compt << " for "<< N<<" Queen"<<  std::endl;
	return 0;
}