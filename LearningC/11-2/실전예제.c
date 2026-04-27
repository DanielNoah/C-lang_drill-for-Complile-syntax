#include <stdio.h>

void lenCompareGet(char *str, int size);

int main(void)
{
	char str[] = {};

	lenCompareGet(str, sizeof(str));
	printf("입력한 문자 : %s", str);

	return 0;
}

void lenCompareGet(char *str, int size)
{
	int ch, i = 0;
	
	ch = getchar();
	while (ch != -1)
	{
		str[i] = ch;
		i++;
		ch = getchar();		
	}
	str[i] = '\0';
	if (sizeof(str[i-1]) > sizeof(str[i]))
	{
		// printf("가장 긴 문자 : %s", *(str[i]-1));
	}
	else
	{
		// printf("가장 긴 문자 : %s", *str[i]);
	}	
}