#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool game_over;
const int width = 20;
const int heigth = 20;
int x, y, pointX, pointY, total;
int snakeX[100], snakeY[100];
int snake_c;
enum Direction{STOP =0, LEFT, RIGHT, UP, DOWN};
Direction snake;
void set()
{
	game_over = false;
	snake = STOP;
	x = width / 2;
	y = heigth / 2;
	pointX = rand() % width;
	pointY = rand() % heigth;
	total = 0;
}
void draw()
{
	system("cls");//clears the console
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;
	for (int i = 0; i < heigth; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == pointY && j == pointX)
			{
				cout << "F";
			}
			else
			{
				bool output = false;
				for (int k = 0; k < snake_c; k++)
				{
					if (snakeX[k] == j && snakeY[k] == i)
					{
						cout << "o";
						output = true;
					}
				}
				if (!output)
				{
					cout << " ";
				}
				
			}
			

			if (j == width - 1)
			{
				cout << "#";
			}
			
		}
		cout << endl;
	}
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "Score: " << total << endl;
}
//w - up
//a- right
//d- left
//s- up
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			snake = LEFT;
			break;
		case 'd':
			snake = RIGHT;
			break;
		case 'w':
			snake = UP;
			break;
		case 's':
			snake = DOWN;
			break;
		case 'x':
			game_over = true;
			break;

		}
	}
}
void game_alg()
{
	int snake1x = snakeX[0];
	int snake1y = snakeY[0];
	int snake2x, snake2y;
	snakeX[0] = x;
	snakeY[0] = y;
	for (int i = 1; i < snake_c; i++)
	{
		snake2x = snakeX[i];
		snake2y = snakeY[i];
		snakeX[i] = snake1x;
		snakeY[i] = snake1y;
		snake1x = snake2x;
		snake1y = snake2y;
	}
	switch (snake)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > heigth || y < 0 )
	//{
		//game_over = true;
	//}
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= heigth) y = 0; else if (y < 0) y = heigth - 1;
	for (int i = 0; i < snake_c; i++)
	{
		if (snakeX[i] == x && snakeY[i] == y)
		{
			game_over = true;
		}
	}
	if (x == pointX && y == pointY)
	{
		total = total += 5;
		pointX = rand() % width;
		pointY = rand() % heigth;
		snake_c++;
	}

}
int main()
{
	set();
	while (!game_over)
	{
		draw();
		input();
		game_alg();
		Sleep(10);
	}
	return 0;
}
