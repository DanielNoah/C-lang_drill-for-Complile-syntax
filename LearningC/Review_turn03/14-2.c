#include <stdio.h>
	
int main(void)
{
	int num[3][4] =  // 논리적 구조
	{{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12}};
	// 물리적 구조 int num[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}}; 	
	int count = sizeof(num) / sizeof(num[0]);
	printf("행의 개수 : %d\n", count);
	int i, j;
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++) 
		{
			printf("%5d", num[i][j]);
		}printf("\n");
	}
	

	return 0;
}
