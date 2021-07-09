#pragma once

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

class Grid
{
private:
	int X;
	int Y;
	int** life;
	void render();
	int** temp;
public:
	void new_grid(int x, int y);
	void randomise();
	void in();
	void endless_render();
};