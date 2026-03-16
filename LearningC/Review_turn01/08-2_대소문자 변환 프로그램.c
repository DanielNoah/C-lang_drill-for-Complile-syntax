#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	int i;
	int cnt = 0;
	char str[100];
//	char str2[100]; //
	
//	scanf("%s\n", str1); // 빈칸 포함 문장 출력하기 위해 gets() 함수 사용
	printf("문장 입력 : %s \t", gets(str));
	
//	for (i=0; i<100; i++)  // 어디까지 ~100 (x) -> null문자가 아닐 때까지
	for (i=0; str[i] != '\0'; i++)
	{
		if(isupper(str[i]))
		{
			str[i] = tolower(str[i]);
			cnt++;
		}

	}

	printf("\n바뀐 문장 : "); 
	puts(str);
	
	printf("\n바뀐 문자 수 : %d", cnt);
	
	return 0;
}