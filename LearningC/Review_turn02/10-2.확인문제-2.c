#include <stdio.h>
int month[12] = { 21, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void print_month(int *mp);

int main(void)
{
	print_month(month);
}

void print_month(int *mp)
{
	int i;
	for (int i = 0; i < 12; i++)
	{
	 /* printf("%5d", month[i]); <-포인터 연산으로 각 달의 일수 출력 (16행)
		printf("%5d", *mp++);   <- 포인터 배열로 각 달의 일수 출력 (17행) */
		printf("%5d", mp[i]);
	/*	if(month[i]%5==0) printf("\n");	<- 포인터 배열로 사용해서 출력 개수가 5의 배수면 줄 바꿈 처리 (19행) 
		if(mp[i]%5 == 0) printf("\n"); <- 포인터 배열 건드리지 않고 출력 개수가 5의 배수면 줄바꿈 처리 (20행) */
		if((i+1) % 5 == 0) printf("\n"); // 5개씩 출력하는 방법 

	}
}