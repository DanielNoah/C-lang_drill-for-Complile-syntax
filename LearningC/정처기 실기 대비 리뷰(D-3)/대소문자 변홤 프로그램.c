#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[100];

	printf("문장 입력 : \n");
	gets(str);

	int i;
	int cnt = 0;
//	for(i = 0; i < str[i]; i++)				// 조건 연산 틀림 -> str[i]는 str[99]까지 반복함 =>str[i]가 '\0' NULL 문자를 만날 때까지만 출력!
	for(i = 0; str[i] != '\0'; i++)
	{
		if(isupper(str[i]))
			{
		//		str[i] = islower(str[i]);	// 소문자로 변형 -> islower()는 현재 소문자이면 true 반환하는 boolean 함수
				str[i] = tolower(str[i]);
				cnt++;
			}
//	cnt++; // 소문자로 변환된 문자 개수를 카운팅 해야 하므로 위치는 바뀐 명령문 아래로...
	}

	printf("바뀐 문장 : %s\n", str);			// 코딩 맞음-> str은 배열의 첫번째 주소값을 가리키므로, 전체 문자열 출력함.
	printf("바뀐 문자 수 : %d\n", cnt);

	return 0;
}