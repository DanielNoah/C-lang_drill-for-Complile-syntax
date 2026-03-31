#include <stdio.h>

void input_num(int *pa, int *pb);
void swap_num(void);
void print_num(int a, int b);

int a, b;

int main()
{
 	input_num(&a, &b);
 	swap_num();
 	print_num(a, b);

 	return 0;
}

void input_num(int *pa, int *pb)
{
	printf("입력한 두 정수 값 : ");
	scanf("%d,%d", pa, pb);
} 

void swap_num(void)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
} 

void print_num(int a, int b)
{
	printf("교환한 두 정수 값 : %d,%d", a, b);
}