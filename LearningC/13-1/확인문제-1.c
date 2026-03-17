#include <stdio.h>

void func(void);

int a = 10; //전역변수

int main(void)
{
	a = 20;
	func(); // 호출 아래의 func()함수 호출
	printf("%d", a); // a의 값 func()함수 내부 초기값 출력
	return 0;	
}
void func(void)
{
	a = 30;  // 내부 변수;
}
