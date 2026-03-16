#include <stdio.h>

int main(void)
{
	double a = 3.4;	// double형 변수 선언 
	double *pd = &a; // pd가 double형 변수 a를 가리키도록 초기화
	int *pi;		// int형 변수를 가리키는 포인터
	pi = (int *)pd; // pd값을 형 변환하여 pi에 대입

	printf("%lf\t형변환후: %d\n", *pd, pi);
	return 0;
}