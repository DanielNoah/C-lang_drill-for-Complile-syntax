#include <stdio.h>
/* '포인터에 배열을 저장해서 2차원 문자열 배열을 포인터로 가리켜서 문자열 상수 출력 */	
int main(void)
{
	char animal[5][10] = {"dog", "elephant", "horse", "tiger", "lion"}; 
	char* pary = animal;  // 포인터형(동일한 크기) 변수에 배열명 저장 
	int i, j;

/*	ary[0] = "dog"; 
	ary[1] = "elephant";
	ary[2] = "horse";
	ary[3] = "tiger";
	ary[4] = "lion"; */

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%c ", *(pary++));	// 포인터로 모든 배열 요소 출력 
		}									// (배열명 자체로는 animal[i][j] 출력가능)
		printf("\n");					
	}									

	return 0;
}