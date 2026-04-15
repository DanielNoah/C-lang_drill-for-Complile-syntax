#include <stdio.h>

int main()
{
	int ary[5];

/*	ary = "..."; 배열에 문자열 대입 -> 컴파일 에러 l-value에 사용한 배열명이 컴파일 과정에서 배열이 할당된 메모리 주소 값으로 바뀌기 때문. 
				 ary 배열이 100번지부터 할당되었다면, 다음과 같이 대입하는 것과 동일 100 = "..."; */
	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	scanf("\n%d", &ary[3]);

	printf("%d\n", ary[2]);
	printf("%d\n", ary[3]);
	printf("%d\n", ary[4]);

	return 0;
}