#include <stdio.h>

int main(void)
{
	int chest = 95;
	char size;
	if (chest <= 90) 
	{
		size = 'S';
	}
 /* else if (90 < chest <= 100) // 틀린 조건 표현식 */
	else if ((90 < chest) && (chest <= 100))
	{
		size = 'M';
	}
 /*	else if (chest > 100) // 마지막 조건 분기문은 항상 남은 나머지 하나의 조건식이므로 else! */
	else
	{
		size = 'L';
	}
}