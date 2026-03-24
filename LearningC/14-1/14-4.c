#include <stdio.h>

int main(void)
{
	char animal1[2][3] = {
		{'d', 'o', 'g', '\n'} // 문자열 상수로 하나씩 초기화
	};
	// 문자열 상수로 한 행씩 초기화, 행의 수 생략 가능
	char animal2[][10] = {"dog", "tiger", "rabbit", "horse", "cat"}; // 행의 수를 생략하면, 이때 초기화되는 문자열 상수의 개수가 행의 수가 됨
																	// 남는 저장 공간은 널 문자로 채워짐.
	int i;

	for (i=0; i<5; i++)
	{
		printf("%s ", animal1[i]);
	}
	
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s ", animal2[i]);
	}

	return 0;
}


