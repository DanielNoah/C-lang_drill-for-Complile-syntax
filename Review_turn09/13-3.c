#include <stdio.h>

void assign10(void);
void assign20(void);

int a;

int main(void)
{
	printf("함수 호출 전 a의 값 : %d\n", a); // 전역변수 a 출력

	assign10();
	assign20();

	printf("함수 호출 후 a의 값 : %d\n", a); // 전역변수 a 출력

	return 0;
}

void assign10(void)
{
	a = 10;								// 전역변수 초기화
}

void assign20(void)
{
	int a;								// 지역변수 선언
	a = 20;								// 지역변수 초기화
}
