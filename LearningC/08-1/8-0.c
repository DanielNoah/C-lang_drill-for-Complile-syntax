#include <stdio.h>

int main(void)
{
//	int ary[5] = {10, 20, 30, 40, 50};
	int ary[5];

	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	ary = 10;

	scanf("%d", &ary[3]); // 키보드로 입력받아 네 번째 요소에 저장

	printf("%d\n", ary[2]);
	printf("%d\n", ary[3]);
	printf("%d\n", ary[4]); // 마지막 배열 요소는 초기화를 하지 않았으므로 쓰레기값
	printf("%d\n", ary[5]);


return 0;
} 