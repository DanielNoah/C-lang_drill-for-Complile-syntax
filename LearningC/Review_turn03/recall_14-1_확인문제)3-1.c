#include <stdio.h>

int main(void)
{
	char mark[5][5] = { 0 };

	int i, j;
	for(i = 0; i < 5; i++)		// 행 5번 반복
	{
		for(j = 0; j < 5; j++)	// 열 5번 반복
		{
			if((i==j)||(i+j==4)) mark[i][j] = 'X';
			printf("%5c", mark[i][j]);

		}
		printf("\n");
	}
}