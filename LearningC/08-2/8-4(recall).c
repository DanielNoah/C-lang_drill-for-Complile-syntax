#include <stdio.h>

int main()
{
	char str[80] = "applejam"; //char형 배열 선언 하지 않고, int형으로 선언 X (char형으로 선언 권장->알파벳을 char 1byte에 저장가능)

	printf("문자열 입력 :\n");
	scanf("%s", str);
	printf("최초 문자열 : %s\n", str);
	printf("입력 후 문자열 : %s\n", str);

	return 0;
}