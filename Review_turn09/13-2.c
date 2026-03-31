#include <stdio.h>

int main()
{
	int a = 10, b = 20;
	printf("교환 전 a와 b의 값 : %d, %d\n", a, b);
	{
		int temp;

		temp = a;
		a = b;
		b = temp;	

	}
	printf("%d %d\n", a, b);	// 5행의 변수 a, b는 블록 안에 새로 선언된 
								// 변수 a, b에 의해 사용범위가 가려짐(가장 가까운
								// 블록에 선언된 변수를 사용함.)
	return 0;					// 그러나 중첩된 블록에서 같은 이름의 변수를 선언하면,
}								// 예상치 못한 결과를 얻을 수 있으므로 사용 지양.