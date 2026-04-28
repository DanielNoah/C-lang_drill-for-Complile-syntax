#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[10] = "apple";
	char str2[10] = "pie";
	char *ps1 = "banana";
	char *ps2 = str2;

	printf("최조 문자열 : %s\n", str1);
	strcpy(str1, str2);
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps1);
	printf("바뀐 문자열 : %s\n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열 : %s\n", str1);
	
	strcpy(str1, "banana");
	printf("바뀐 문자열 : %s\n", str1);
	
	// printf("%s\n", c + d); //실행안됨? -> 문자열로 연산할 때는 문자열 연산용 함수를 사용해야함.

	return 0;
}

