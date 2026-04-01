#include <stdio.h>
/* call by value(원본 데이터를 건드리지 않기 때문에 권장) */
int add_ten(int a);

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