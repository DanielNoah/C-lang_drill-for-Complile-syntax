#include <stdio.h>

int main(void)
{
	int a = 10;
	int b = 20;
	char c[10] = "apple";
	char d[10] = "pie";

	printf("%d\n", a + b);
	printf("%s\n", c + d); //실행안됨? -> 문자열로 연산할 때는 문자열 연산용 함수를 사용해야함.

	return 0;
}

