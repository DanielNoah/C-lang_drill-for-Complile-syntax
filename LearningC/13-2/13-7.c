#include <stdio.h>

/* 주소를 전달하는 함수 */

void add_ten(int *pa); // 매개변수 포인터 pa 선언

int main(void)
{
	int pa = 10;
	
	add_ten(&pa);

	printf("a : %d\n", pa);

	return 0;
}

void add_ten(int *pa)
{
	*pa = *pa + 10;
}
