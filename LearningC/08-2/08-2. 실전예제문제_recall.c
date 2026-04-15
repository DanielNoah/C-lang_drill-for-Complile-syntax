#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[90];
	int i = 0;

	printf("문장 입력 : ");
	gets(str);
	puts(str);

	for( i=0; str[i] != '\0'; i++ )
	{
		 if (isupper(str[i]))		  // if ((str > 'A') && (str < 'z'))
		 {
		 	str[i] = tolower(str[i]); // str[i] = 'a' - 'A';
		 }
	}

	printf("바뀐 문장 : ");
	puts(str);

	return 0;
}