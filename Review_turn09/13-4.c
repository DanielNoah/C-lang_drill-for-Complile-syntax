#include <stdio.h>

void auto_func(void);
void static_func(void);

int main(void)
{
	int i;

	printf("일반 지역 변수(auto)를 사용한 함수...\n");
	for (i = 0 ; i < 3; i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
	for (i = 0 ; i < 3; i++)
	{
		static_func();
	}

	return 0;
}
	
void auto_func(void)
{
	auto int a = 0;

	a++;
	printf("%d\n", a);
}

void static_func(void)
{
	static int a = 0;	// 정적지역변수 선언 및 초기화

	a++;				// 함수 루틴이 끝나도 a의 값 유지됨.
	printf("%d\n", a);

}