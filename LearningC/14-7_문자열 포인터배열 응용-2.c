#include <stdio.h>
/* '포인터 배열'로 여러 개의 문자열 출력 -> 같은 포인터가 많이 필요한 경우 배열을 사용하는 것이 좋음 */	
int main(void)
{
	char* ary[5];

	ary[0] = "dog";
	ary[1] = "elephant";
	ary[2] = "horse";
	ary[3] = "tiger";
	ary[4] = "lion";
	

	 // 포인터 배열 선언.(각 배열 요소의 자료형이 포인터형이므로 배열명 앞에 별을 붙임.)
	int i, j;

/*	ary[0] = "dog"; 
	ary[1] = "elephant";
	ary[2] = "horse";
	ary[3] = "tiger";
	ary[4] = "lion"; */

	for (i = 0; i < 5; i++)
	{
			printf("%s ", ary[i]);

	}
	printf("\np%s", ary[3]+0);

	return 0;
}
