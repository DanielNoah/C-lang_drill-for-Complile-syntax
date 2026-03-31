#include <stdio.h>

int main()
{
	int a = 10;  // double형 변수 선언
	int *p = &a; // pd가 double형 변수 a를 가리키도록 초기화
	double *pd;  // int형 변수를 가리키는 포인터
	pd = &a;

//	pd = p; // 초기화안된 포인터 pd에 포인터 p의 값(변수 a의 주소 값) 대입
	printf("%lf\n", (int *)pd);

	return 0;
}