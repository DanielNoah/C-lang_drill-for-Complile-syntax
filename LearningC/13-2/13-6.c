#include <stdio.h>Í

/* 값을 복사해서 전달하는 함수 */

int add_ten(int a); // 함수 프로트타입 선언

int main(void)
{
	int a = 10;

	a = add_ten(a);

	printf("a : %d\n", a);

	return 0;
}

int add_ten(int a)
{
	a = a + 10;
	return a;
}

