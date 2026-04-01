#include <stdio.h>

void input_data(int *pa, int *pb);
void swap_data(void);
void print_data(int a, int b);

int a, b;

int main()
{
	input_data(&a, &b);
	swap_data();
	print_data(a, b);

	return 0;
}

void input_data(int *pa, int *pb) // int *pa = &a / int *pb = &b;
{
	printf("두 정수 입력 :"); // 표제에는 따로 출력
	scanf("%d %d", pa, pb);	// scanf 표시형식 문자열 사이 콤마 불필요!!
}
	
void swap_data(void)
{
	int temp;
//	static int a, b;	// static 선언도 필요없음.
//	input_data(&a, &b); // 인풋함수 호출 X
	
	temp = a;
	a = b;
	b = temp;
}

void print_data(int a, int b)

{
	printf("두 정수 출력 : %d, %d", a, b);
}