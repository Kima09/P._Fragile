#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

void move(int x, int y)
{
	// x와 y축을 설정하는 구조체입니다.
	COORD position = { x, y };

	// 콘솔 커서의 좌표를 설정하는 함수입니다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	// y축은 +가 아래쪽, -가 위쪽 방향입니다.

	// COORD: x, y 정보를 저장하는 구조체

		//int x = 5;
		//int y = 5;
		//
		//move(x, y);
		//printf("O");

		//while (1)
		//{
		//	int input = _getch();
		//	if (input == 224)
		//	{
		//		input = _getch();
		//	}
		//	switch (input)
		//	{
		//	case UP:
		//		printf("UP\n");
		//		break;
		//	case DOWN:
		//		printf("DOWN\n");
		//		break;
		//	case LEFT:
		//		printf("LEFT\n");
		//		break;
		//	case RIGHT:
		//		printf("RIGHT\n");
		//		break;
		//	default:
		//			printf("Exception\n");
		//			break;
		//	}
		//}

	int x = 5;
	int y = 5;
	move(x, y);
	printf("★");

	while (1)
	{
		int input = _getch();
		switch (input)
		{
		case UP:

			y -= 1;
			break;
		case DOWN:

			y += 1;
			break;
		case LEFT:

			x -= 2;
			break;
		case RIGHT:

			x += 2;
			break;
		}
		if (x < 0)
		{
			x += 2;
		}
		if (y < 0)
		{
			y++;
		}
		system("cls");
		move(x, y);
		printf("★");
	}
	return 0;
}