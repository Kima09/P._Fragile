#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <conio.h>

int screen_index;

HANDLE screen[2];

void initialize()
{
	CONSOLE_CURSOR_INFO cursor;


	//화면 버퍼를 2개 생성합니다.

	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL
	);

	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE, 0, NULL,
		CONSOLE_TEXTMODE_BUFFER, NULL
	);

	cursor.dwSize = 1;
	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);

}

void flip()
{
	SetConsoleActiveScreenBuffer(screen[screen_index]);

	// 1 <- 0
	// 0 <- 1

	screen_index = !screen_index;
}

void clear()
{
	COORD position = { 0,0 };
	DWORD dword;
	CONSOLE_SCREEN_BUFFER_INFO console;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(handle, &console);

	int width = console.srWindow.Right - console.srWindow.Left + 1;
	int height = console.srWindow.Bottom - console.srWindow.Top + 1;

	FillConsoleOutputCharacter(screen[screen_index], ' ', width * height, position, &dword);
}

void release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}

void render(int x, int y, const char* text)
{
	DWORD dword;
	COORD position = { x,y };

	SetConsoleCursorPosition(screen[screen_index], position);
	WriteFile(screen[screen_index], text, strlen(text), &dword, NULL);
}

void move(int x, int y)
{
	// x와 y축을 설정하는 구조체입니다.
	COORD position = { x, y };

	// 콘솔 커서의 좌표를 설정하는 함수입니다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

int main()
{
	int x = 5;
	int y = 5;

	initialize();

	while (1)
	{
		flip();
		clear();
		render(x, y, "★");
		if ((GetAsyncKeyState(VK_RIGHT)) & 0x0001)
		{
			x++;
		}
		if ((GetAsyncKeyState(VK_LEFT)) & 0x0001)
		{
			x--;
		}
		if ((GetAsyncKeyState(VK_UP)) & 0x0001)
		{
			y--;
		}
		if ((GetAsyncKeyState(VK_DOWN)) & 0x0001)
		{
			y++;
		}
		flip();
		clear();
		render(x, y, "★");
	}

	release();

	return 0;
}