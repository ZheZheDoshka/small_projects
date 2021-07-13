#pragma once
#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>


using namespace std;
class Grid;

class Snake
{
private:
	int Head_X;
	int Head_Y;
	int weight = 1;
	char dir;
	int prev[2] = { 0,0 };
	int body[100][2];
	char dir_ready = 'sd';
public:
	friend Grid;
	void input();
	bool alive = true;
};

class Grid
{
private:
	int Fruit_X = 5;
	int X, Y;
	bool fruit=true;
	int Fruit_Y = 2;
	int** life;
public:
	void new_grid(int x, int y, Snake& snek);
	void logic(Snake& snek);
	void render(Snake& snek);
	
};