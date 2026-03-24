/* C언어 포인터, 메모리 구조, 네트워크 OSI 7계층 지식은 GICSP의 'Endpoint Security' */
#include <stdio.h>
int main(void)
{
	int sum[5][6] = {
		{1, 2, 3, 4, 5}, 
		{6, 7, 8, 9, 10}, 
		{11, 12, 13, 14, 15}, 
		{16, 17, 18, 19, 20}
	};

	int i, j;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			sum[i][5] += sum[i][j];
			sum[4][j] += sum[i][j];
			sum[4][5] += sum[i][j];
		}
	}
	
	for(i = 0; i < 5; i ++)
	{
		for(j = 0; j < 6; j++)
		{
			printf("%5d", sum[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
