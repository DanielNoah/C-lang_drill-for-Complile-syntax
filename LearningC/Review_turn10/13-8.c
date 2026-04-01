#include <stdio.h>
/* 'call by reference'에 가까운 주소를 반환하는 함수 */ 
int* sum(int a, int b); // *int형* 주소를 반환하는 함수 선언(프로토 타입)

int main(void)
{
	int* resp; 
//	resp = *sum(10, 20);	// 반환된 주소는 resp(result pointer)에 저장 역참조가 아니라, 함수 호출이므로 int* 형인 sum 함수를 호출해야...
	resp = sum(10,20);		
	
	printf("첫 번째 호출한 두 정수의 합 : %d\n", *resp);

	resp = sum(30,50);								// res 지역 정적 변수 저장 공간은 메모리에 잔존하므로 언제든지 값을 변경해서 사용 가능...
	printf("두 번째 호출한 두 정수의 값 : %d\n", *resp);	
}


//int* sum(a, b)			// 주소를 반환하고 *int형* 매개변수를 받는 함수 
int* sum(int a, int b)	// 정적 지역 변수의 주소를 반환하거나, 호출하는 함수(main)에 있는 변수의 주소를 인수로 받는 경우(13-7.c) 그 주소를 다시 반환 가능.
{
	static int res;		// 정적 지역 변수 res 선언
	int res;			// 안할 시 -> warning: address of stack memory associated with local variable 'res' returned [-Wreturn-stack-address]
	res = a + b;

	return &res;
}
