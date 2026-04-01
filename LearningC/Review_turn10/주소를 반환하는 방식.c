#include <stdio.h>

int* sumFunc(int a, int b); // int*형의 sumFunc함수 선언

int main()
{
	int* resp;			// 합을 구하는 sumFunc 함수의 반환값(주소)을 저장하는 포인터 변수 resp 

	resp = sumFunc(30, 50); // 주소 값을 반환받기 위한 포인터 변수 resp 초기화
	printf("Callee의 반환값 : %d\n", *resp);
}

int* sumFunc(int a, int b) // callee 함수 -> static local variable 선언 필요
{
//	static int sum; // 함수 호출 이후 메모리 공간 회수되면(staitc 선언X), 아래 경고 메시지 발생 
	int sum;		// warning: address of stack memory associated with local variable 'sum' returned [-Wreturn-stack-address]
					// 
					// * 의미 : 함수 내에서 선언된 지역 변수('sum')의 메모리 주소를 반환했을 때 발생함. 
					// 함수가 종료되면 해당 변수는 스택 메모리에서 사라지므로, 반환된 주소는 유효하지 않은 
					// 데이터(댕글링 포인터)를 가리키게 되어 심각한 런타임 오류나 잘못된 값을 유발할 수 있음 
					// -> return 값을 sum으로 변경하거나, static 선언
					// 
					// 동적할당(malloc)해서 사용하거나, 외부메모리에 포인터로 인자를 받는 방법도 가능
					// 1) 동적 할당 (malloc): 힙(Heap) 메모리를 사용하여 함수 종료 후에도 주소를 유지함.
					// 단, free로 메모리 해제 필요).
					// int* getSum() {
    				//		 int* sum = malloc(sizeof(int)); ✅ 해결: 힙 메모리 사용
				   	// 		*sum = 10;
    				// 		return sum;
					// }
					// 2) 외부 메모리 사용: 함수 외부에서 선언된 변수의 포인터를 인자로 전달받아 값을 저장. -> Call by Reference
	sum = a + b;

	return &sum;
}