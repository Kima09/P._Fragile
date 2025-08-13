#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void shuffle(int list[], int i)
{

	for (int f = 0;f < i;f++)
	{
		int a = rand() % i;
		int b = rand() % i;

		int temp = list[a];
		list[a] = list[b];
		list[b] = temp;

	}
}

void update_hp(int hp)
{
	for (int i = 0;i < hp;i++)
	{
		printf(">");
	}
}

int main()
{
#pragma region rand 함수
	// 0 ~ 32767 사이의 난수 값을 반환하는 함수입니다.

	// UTC 기준으로 1970년 1월 1일 0시 0분 0초부터 경과된
	//시간을 초(sec)로 반환하는 함수입니다.

		//srand(time(NULL));
		//
		//int random = rand() % 10 + 1;
		//printf("%d\n", random);

#pragma endregion

#pragma region Shuffle Function

	//int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//
	//srand(time(NULL));
	//shuffle(list, sizeof(list)/sizeof(int));
	//
	//for (int i = 0;i < sizeof(list) / sizeof(int);i++)
	//{
	//	printf("%d ", list[i]);
	//}
	//printf("\n");

#pragma endregion

#pragma region Game
	srand(time(NULL));
	int com = rand() % 50 + 1;

	int hp = 5;
	while (hp > 0)
	{
		int answer;
		printf("\nChance: ");
		update_hp(hp);
		printf("\n1 ~ 50 범위에서 한 정수를 입력하세요: ");
		scanf_s("%d", &answer);
		if (answer == com)
		{
			printf("\nVICTORY\n");
			break;
		}
		else if (answer < 1 || answer>50)
		{
			printf("\n범위 내의 값이 아닙니다.\n");
			hp -= 1;
		}
		else if (answer < com)
		{
			printf("\n컴퓨터의 값보다 작습니다.\n");
			hp -= 1;
		}
		else
		{
			printf("\n컴퓨터의 값보다 큽니다.\n");
			hp -= 1;
		}
		if (hp == 0)
		{
			printf("\n컴퓨터의 값은 %d입니다.", com);
			printf("\nDEFEATED\n");
			break;
		}
	}

#pragma endregion


	return 0;
}