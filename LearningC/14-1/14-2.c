#include <stdio.h>

int main(void)
{
	int num[][2] = {1, 2, 3, 4, 5, 6};

	int i, j, cnt;

	for(i=0; i<3; i++)
	{
		for (j=0; j<4; j++)
		{
			printf("%5d", num[i][j]);
			cnt = sizeof(num) / sizeof(num[0]);
		}
		printf("\n");
		printf("%d", cnt);
	}

	return 0;
}
