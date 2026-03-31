#include <stdio.h>

int main(void)
{
	int a;
	int *pa;

	pa = &a;

	scanf("%d", pa);
	scanf("%d", &a);
	scanf("%d", &*pa);

	printf("포인터로 포인터 주소 값 출력 : %p\n", pa);
	printf("포인터로 a 값 출력 : %d\n", *pa);
	printf("a값 출력 : %d\n", a);

	return 0;
}