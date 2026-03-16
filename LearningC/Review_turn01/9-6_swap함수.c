#include <stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
	int a = 10, b = 20;
/*	int *pa = &a;
	int *pb = &b; */

	swap(&a, &b);   // 틀린 부분 swap(&pa, &pb) -> 아래 void함수 매개변수에 대입되는 인자 &a, &b (포인터 선언 및 초기화)
	printf("a:%d, b:%d\n", a, b);

	return 0;
}
void swap(int *pa, int *pb) // 매개변수
{
	int temp;

	temp = *pa;		// 틀린 부분 swap 함수 내부에서는 main함수의 변수(a,b) 호출 X
	*pa = *pb;	
	*pb = temp;

}
