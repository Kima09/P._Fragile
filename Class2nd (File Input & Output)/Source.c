#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void load(const char* file_name)
{
	FILE* file = fopen(file_name, "r");
	char buffer[SIZE] = { 0, };
	fread(buffer, 1, SIZE, file);

	printf("%s", buffer);

	fclose(file);
}

int main()
{
#pragma region 파일 입출력

#pragma region File Write

	// fopen(첫 번째 매개 변수): 파일의 이름
	// fopen(두 번째 매개 변수): 입력 & 출력 모드

	// 모드
	// "r": 읽기 전용 (파일이 없을 때: NULL)
	// "w": 쓰기 전용 (새로 파일을 생성)
	// "a": 추가 모드 (새로 파일을 생성 - 기존에 있는 파일에 내용을 추가)

	//FILE* file = fopen("data.txt", "w");
	//
	//fputs("strength: \n", file);
	//fputs("dexterity: \n", file);
	//fputs("wisdom: \n", file);
	//fputs("intelligence: \n", file);
	//fputs("constitution: ", file);
	//
	//fclose(file);

#pragma endregion

#pragma region File Read
	//FILE* file = fopen("wanzer.txt", "r");
	//char buffer[SIZE] = {0, };
// 버퍼의 크기는 크게 잡는 것이 좋지만,
// 과도하게 큰 값은 틀린 값을 출력시킬 수 있습니다.
// 
// 1. buffer: 읽을 데이터를 저장할 메모리
// 2. element size: 각 데이터 항목의 크기
// 3. element count: 데이터를 읽어올 데이터의 항목의 수
// 4. stream: 데이터를 읽어올 파일 포인터

	//fread(buffer, 1, SIZE, file);
	//
	//printf("%s", buffer);
	//
	//fclose(file);

	load("wanzer.txt");
#pragma endregion

#pragma endregion


	return 0;
}