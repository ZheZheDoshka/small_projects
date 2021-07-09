#include "Grid_Of_Life.h"


void Grid::new_grid(int x, int y)
{
	X = x;
	Y = y;
	life = new int*[x];
	for (int i = 0; i < x; i++)
	{
		life[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j <y; j++)
		{
			life[i][j] = 0;
		}
	}
	temp = new int* [x];
	for (int i = 0; i < x; i++)
	{
		temp[i] = new int[y];
	}
}

void Grid::randomise()
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			life[i][j] = rand() % 2;
		}
	}
}

void Grid::in()
{
	cout << "========================================" << endl << "Enter Grid"
		<< endl << "========================================" << endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> life[j][i];
		}
		cout << endl;
	}
	cout << endl <<"========================================" << endl;
}

void Grid::render()
{
	cout << "========================================" << endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (life[j][i] == 0)
			{
				cout << ' ';
			}
			else
			{
				cout << '@';
			}
		}
		cout << endl;
	}
	cout << endl << "========================================" << endl;
}

void Grid::endless_render()
{
	int neighbors=0;
	{
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				if (j + 1 < Y)
				{
					if (life[i][j + 1] != 0)
						neighbors++;
				}
				if (j - 1 >= 0)
				{
					if (life[i][j - 1] != 0)
						neighbors++;
				}
				if (i + 1 < X)
				{
					if (j + 1 < Y)
					{
						if (life[i + 1][j + 1] != 0)
							neighbors++;
					}
					if (life[i + 1][j] != 0)
						neighbors++;
					if (j - 1 >= 0)
					{
						if (life[i + 1][j-1] != 0)
							neighbors++;
					}
				}
				if (i -1 >=0)
				{
					if (j + 1 < Y)
					{
						if (life[i-1][j + 1] != 0)
							neighbors++;
					}
					if (life[i-1][j] != 0)
						neighbors++;
					if (j - 1 >= 0)
					{
						if (life[i -1][j - 1] != 0)
							neighbors++;
					}
				}
				if (life[i][j] != 0)
				{
					if (neighbors<2)
					{
						temp[i][j] = 0;
					}
					if (neighbors > 3)
					{
						temp[i][j] = 0;
					}
				}
				else
				{
					if (neighbors = 3)
					{
						temp[i][j] = 1;
					}
				}
				neighbors = 0;
			}
		}
		for (int i = 0; i < X; i++)
		{
			for (int j = 0; j < Y; j++)
			{
				life[i][j] = temp[i][j];
			}
		}
	}
	render();
}