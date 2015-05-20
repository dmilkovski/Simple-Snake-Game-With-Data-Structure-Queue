#define _CRT_NO_SECURE_WARNIGS
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"Queue.h"
#include"Song.h"

#define WIDTH 80
#define HEIGHT 25

#define ClearScreen system ("CLS")
#define SnakeElement '*'
#define SnakeFood '@'
#define SnakeSpeed 100
#define SnakeInitializeSize 5

typedef enum _Direction 
{
	UP = 0,
	DOWN = 1,
	RIGHT = 2,
	LEFT = 3
} Direction;

int RandomNumber (int min, int max)
{
	float randomNum = (float) rand() / (float) RAND_MAX;
	return (int) (min + randomNum * (max - min));
}

void GoToPosition(COORD position)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void PrintSnake (Queue *snake)
{
	Node* tmp = snake->front;
	while (tmp != NULL)
	{
		GoToPosition(tmp->data);
		printf("%c", SnakeElement);
		tmp = tmp->next;
	}
}

int main()
{
	system("COLOR 1A");
	Queue *snake = Queue_Init();

	COORD screenResolution = {WIDTH, HEIGHT};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), screenResolution);

	SetConsoleTitle("TU-Snake");

	COORD directions[4] = {
		{0, -1},
		{0, 1},
		{1, 0},
		{-1, 0},
	};

	Direction direction = LEFT;

	unsigned int keyboardInput = 0;
	double snakeSpeed = SnakeSpeed;

	COORD food = {RandomNumber(0, WIDTH), RandomNumber(0, HEIGHT)};
	int centerX = WIDTH / 2;
	int centerY = HEIGHT / 2;

	//InitSnake
	for (int i = 0; i < SnakeInitializeSize; i++)
	{
		COORD position = { centerX - i , centerY};
		Queue_Push(snake, position);
	}

	PrintSnake(snake);

	while (1)
	{
		if (_kbhit() == 1)
		{
			keyboardInput = _getch();

			switch (keyboardInput)
			{
			case 119 : //up
				if (direction != DOWN)
					direction = UP;
				break;
			case 115 : //down
				if (direction != UP)
					direction = DOWN;
				break;
			case 97 : //left
				if (direction != RIGHT)
					direction = LEFT;
				break;
			case 100 : //right
				if (direction != LEFT)
					direction = RIGHT;
				break;
			default:
				break;
			}
		}
		
		COORD snakeHead = Queue_Back(snake);
		COORD nextDirection = directions[direction];
		COORD snakeNewHead = {snakeHead.X + nextDirection.X, snakeHead.Y + nextDirection.Y};

		//check for collisions
		if (snakeNewHead.X < 0 || snakeNewHead.Y < 0 || 
			snakeNewHead.X > WIDTH || snakeNewHead.Y > HEIGHT || Queue_Contains (snake, snakeNewHead))
		{
			char text[] = "!!!Game is over!!!";
			COORD startPoint = {centerX - strlen(text)/2, centerY};
			GoToPosition(startPoint);
			system("COLOR CF");
			printf("%s", text);
			PlaySong();
			break;
		}

		//add new head to snake
		Queue_Push(snake, snakeNewHead);

		//check for grow
		if (snakeNewHead.X == food.X && snakeNewHead.Y == food.Y)
		{
			food.X = RandomNumber(0, WIDTH);
			food.Y = RandomNumber(0, HEIGHT);
			if (snakeSpeed - 1 > 1)
				snakeSpeed--;
		}
		else
		{
			Queue_Pop(snake);	
		}

		PrintSnake(snake);

		GoToPosition(food);
		printf("%c", SnakeFood);


		if (snakeSpeed - 0.1 > 1)
			snakeSpeed -= 0.1;
		Sleep((int)snakeSpeed);
		ClearScreen;
	}

	system("pause > ''");
	return 0;
}