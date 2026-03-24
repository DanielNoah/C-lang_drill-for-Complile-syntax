#include <stdio.h>
/* 여러 개의 1차원 배열을 2차원 배열처럼 사용 */
int main(void)
{
	int ary1[4] = {1,2,3,4};	// 1차원 배열의 선언과 초기화
	int ary2[5] = {11,12,13,14}; //  
	int ary3[5] = {21,22,23,24,35};
	int *pary[3] = {ary1, ary2, ary3}; // 포인터 배열에 각 배열명 초기화
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", pary[i][j]);
		}
		printf("\n");
	}
	printf("%5d", pary[2][2]); // pary[2]가 연결하고 있는 배열의 세 번째 요소

	return 0;
}