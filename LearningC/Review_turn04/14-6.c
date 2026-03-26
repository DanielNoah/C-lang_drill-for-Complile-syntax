#include <stdio.h>
/* '포인터 배열'로 여러 개의 문자열 출력 -> 같은 포인터가 많이 필요한 경우 배열을 사용하는 것이 좋음 */	
int main(void)
{
/*	char animal[5][20] = {"dog", "elephant", "horse", "tiger", "lion"}; */
	char* pary[5];						// 포인터 배열 선언.(각 배열 요소의 자료형이 포인터형이므로 배열명 앞에 별을 붙임. )
/*	char* pary = animal; 
	int i, j;	*/
	int i;

	pary[0] = "dog"; 
	pary[1] = "elephant";
	pary[2] = "horse";
	pary[3] = "tiger";
	pary[4] = "lion"; 

	for (i = 0; i < 5; i++)
	{
//		for (j = 0; j < 20; j++)
//		{
		printf("%s ", pary[i]);	
//		}
	}

	return 0;
}
