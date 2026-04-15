#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNIN

int main(void)
{
	char str[100];
	int i = 0;
	int cnt = 0;

	printf("문장 입력 : ");
	gets(str);
	puts(str);
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 'A') && (str[i] < 'Z')) //ASCII 코드값과 비트연산자 이용
		{
			str[i] += ('a' - 'A');
			cnt++;	
		}
	}
	printf("바뀐 문장 : ");
	puts(str);
	printf("바뀐 문자 수 : %d\n", cnt);

	return 0;
}