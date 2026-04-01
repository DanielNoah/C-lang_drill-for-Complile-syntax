#include <stdio.h>

void add_ten(int* pa);

int main(void)
{
	int a = 10;

	add_ten(&a);	// 호출하는 함수(main)에 있는 변수의 주소를 인수로 받는 경우 그 주소를 다시 반환 가능.
	printf("a : %d\n", a);

	return 0;

}

void add_ten(int* pa)
{
	*pa = *pa + 10;

}