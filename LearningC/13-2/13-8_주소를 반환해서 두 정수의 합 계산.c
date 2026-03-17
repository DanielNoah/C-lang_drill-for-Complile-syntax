#include <stdio.h>

int *sum(int a, int b); // int형 변수의 주소를 반환하는 함수 선언(프로토타입)

int main(void)
{
	int *resp;	// 반환값을 저장할 포인터 resp(result pointer)

	resp = sum(30, 50);	// 반환된 주소는 resp에 저장
	printf("%d\n", *resp);	// resp가 가리키는 변숫값 출력

}

int *sum(int a, int b) // int형 변수의 합을 반환하는 함수
{ 
	static int res; // 정적 지역 변수(result) 
					// *sum() 함수 호출 이후에도 res값 그대로 유지함.
	res = a + b;	// 두 정수의 합을 res(result)

	return &res;	// 정적 지역 변수의 주소 반환

}
