#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

	char str[100];
	int i;
	int cnt = 0; // cnt값 초기화 필요

/*	scanf("%s\n", str); // gets 함수 사용 */
	printf("문장 입력 : %s ", gets(str));
	for (i = 0; str[i] != '\0'; i++)  // 정확한 조건연산 비교
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
			cnt++;
		/*	printf("변환한 문자열 :%u\n", tolower(str[i]));  // 바로 출력하기보단 str[i] 변수에 변환값 대입시킨 후 해당 변수로 출력해야하고, 위치가 for문 바깥으로 나가서 최종 문자열을 출려 */
			
		} 
	}

	printf("\n바뀐 문장 :%s\n", str);  
	/* cnt++; for문을 빠져나오기 전에 카운팅*/
	printf("변환문자 수 : %d", cnt);

return 0;
}


