
#include "snake.h"

void Grid::new_grid(int x, int y, Snake& snek)
{
	X = x;
	Y = y;
	life = new int* [x];
	for (int i = 0; i < x; i++)
	{
		life[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			life[i][j] = 0;
		}
	}
	snek.Head_X = X / 2;
	snek.Head_Y = Y / 2;
}

void Snake::input()
{
	if (_kbhit())
	{
	dir_ready = (_getch());
	if ((dir_ready == 'a')|| (dir_ready == 's') || (dir_ready == 'w') || (dir_ready == 'd'))
	{
		dir = dir_ready;
	}
	}
}

void Grid::logic(Snake& snek)
{
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < Y; j++)
		{
			life[i][j] = 0;
		}
	}
	switch (snek.dir)
	{
	case 'a':
	 {
		snek.Head_X--;
		break;
	 }
	case 's':
	{
		snek.Head_Y++;
		break;
	}
	case 'w':
	{
		snek.Head_Y--;
		break;
	}
	case 'd':
	{
		snek.Head_X++;
		break;
	}
	default:
		break;
	}
	if (snek.Head_X < 0)
	{
		snek.Head_X = snek.Head_X + X;
	}
	if (snek.Head_Y < 0)
	{
		snek.Head_Y = snek.Head_Y + Y;
	}
	if (snek.Head_X >= X)
	{
		snek.Head_X = snek.Head_X - X;
	}
	if (snek.Head_Y >= Y)
	{
		snek.Head_Y = snek.Head_Y - Y;
	}
	for (int i = snek.weight-2; i > 0; i--)
	{
		snek.body[i][0] = snek.body[i-1][0];
		snek.body[i][1] = snek.body[i-1][1];
	}
	snek.body[0][0] = snek.prev[0];
	snek.body[0][1] = snek.prev[1];
	for (int i = 0; i < snek.weight - 1; i++)
	{
		life[snek.body[i][0]][snek.body[i][1]] = 3;
	}
	if (!fruit)
	{
		fruit = true;
		Fruit_X = rand() % X;
		Fruit_Y = rand() % Y;
	}
	life[Fruit_X][Fruit_Y] = 1;
	life[snek.Head_X][snek.Head_Y] = 2;
	if ((snek.Head_X == Fruit_X) && (snek.Head_Y == Fruit_Y))
	{
		life[Fruit_X][Fruit_Y] = 0;
		fruit = false;
		snek.weight++;
	}
	for (int i = 0; i < snek.weight - 1; i++)
	{
		if ((snek.Head_X == snek.body[i][0]) && (snek.Head_Y == snek.body[i][1]))
		{
			snek.alive = false;
		}
	}
	snek.prev[0] = snek.Head_X; snek.prev[1] = snek.Head_Y;
}

void Grid::render(Snake& snek)
{
	system("cls");
	cout << "weight = " << snek.weight << endl;
	for (int j = 0; j < X; j++)
	{
		cout << "==";
	}
	cout << endl;
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (life[j][i] == 0)
			{
				cout << "  ";
			}
			if (life[j][i] == 1)
			{
				cout << "@ ";
			}
			if (life[j][i] == 2)
			{
				cout << "O ";
			}
			if (life[j][i] == 3)
			{
				cout << "o ";
			}
		}
		cout << endl;
	}
	for (int j = 0; j < X; j++) 
	{
		cout << "==";
	}
}