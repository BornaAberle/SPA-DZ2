#include "game_of_life.h"

bool game_of_life::random_value()
{
	if (rand() % 3 == 1) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool game_of_life::cell_taken(int i, int j)
{
	int count = 0;

	if (_generation[i - 1][j - 1] == true) 
	{
		count++;
	}
	if (_generation[i - 1][j] == true) 
	{
		count++;
	}
	if (_generation[i - 1][j + 1] == true) 
	{
		count++;
	}

	if (_generation[i][j - 1] == true) 
	{
		count++;
	}
	if (_generation[i][j + 1] == true) 
	{
		count++;
	}

	if (_generation[i + 1][j - 1] == true) 
	{
		count++;
	}
	if (_generation[i + 1][j] == true) 
	{
		count++;
	}
	if (_generation[i + 1][j + 1] == true) 
	{
		count++;
	}

	if ((count == 3 || count == 2) && _generation[i][j] == true || count == 3 && _generation[i][j] == false) 
	{
		return true;
	}
	else {
		return false;
	}
}

game_of_life::game_of_life()
{
	srand(time(0));
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++) 
		{
			_generation[i][j] = random_value();
		}
	}
}

void game_of_life::next_generation()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			_next_generation[i][j] = cell_taken(i, j);
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			_generation[i][j] = _next_generation[i][j];
		}
	}
}

void game_of_life::draw()
{
	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++) 
		{
			if (_generation[i][j] == false)
			{
				cout << "-";
			}
			else {
				cout << "*";
			}
			
		}
		cout << endl;
	}
}
