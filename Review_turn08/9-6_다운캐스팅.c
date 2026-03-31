#include <stdio.h>

int main()
{
	double a = 3.4;
	double *pd = &a; // pd가 double형 변수 a를 가리키도록 초기화
	int *pi;		 // 가리키는 형이 int 자료형인 포인터 pi 선언
	pi = (int *)pd;  // int형 포인터 pi에 double형 포인터 pd 대입 (int형으로 다운캐스팅)

	printf("%lf", pi);

	return 0;
}


