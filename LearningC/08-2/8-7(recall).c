#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	char str[5];

	str[0] = 'O';
	str[1] = 'K';
	str[2] = '\0';  // 올바른 코딩 습관(메모리 어딘가에 있는 널 문자로 인해 OK뒤의 쓰레기값 출력 방지)
	printf("%s\n", str);

	return 0;
}