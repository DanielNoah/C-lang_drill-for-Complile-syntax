#include <stdio.h>

int main(void)
{
	char ch;
	int len = 0, max = 0;

	// ch = getchar
	
	while (1)
	{
		ch = getchar();
			if (ch == -1)
				break;
		while (ch != '\n')
		{
			printf("%c", ch);
			// len++;
			ch = getchar();	
		}
		printf("\n");
		// printf("문자 길이 : %d\n", len);	
		
	}
	// if(len > max) max = len;
	// 	printf("문자 길이가 가장 긴 문장의 길이 : %d", max);	
	
	return 0;
}
