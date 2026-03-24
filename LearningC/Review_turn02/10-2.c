#include <stdio.h>

int main(void)
{
	int ary[3];			// 배열 선언
	int *pa = ary;		// 포인터에 배열명 저장 (->'포인터 배열'')
	int i;				

	*pa = 10;
	*(pa + 1) = 20;
	pa[2] = pa[0] + pa[1];

	for (i = 0; i < 3; i++)
	{
		printf("%5d\n", pa[i]);
	}

	return 0;

}