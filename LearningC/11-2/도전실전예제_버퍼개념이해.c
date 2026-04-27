#include <stdio.h>

int main(void)
{
	char ch;
	int cnt, max = 0;

	while (1)
	{
		ch = getchar();
		if (ch == -1) break;
		cnt = 0;
		while (ch != '\n')
		{
			printf("%c", ch);
			cnt++;
			// max++;
			ch = getchar();
		}
		printf("문자 수 %d\n", cnt);
		if (max < cnt) max = cnt;		// max 초기값은 0부터 시작하지만,
		printf("\n");					// cnt 초기값이 처음에 저장됨. 
										// 그러므로 기존 cnt 값보다 큰 cnt값이 
	}									// 계속해서 max에 대입됨.
	printf("가장 긴 문자열 수 %d\n", max);

	return 0;
}