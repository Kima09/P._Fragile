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

	int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	srand(time(NULL));
	shuffle(list, sizeof(list)/sizeof(int));

	for (int i = 0;i < sizeof(list) / sizeof(int);i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

#pragma endregion



	return 0;
}