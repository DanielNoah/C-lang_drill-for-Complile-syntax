#include <stdio.h>

int add_ten(int a);

int main()
{
	int a = 10;

	add_ten(a);
	printf("Callee의 return값 : %d\n", a);

	a = add_ten(a); // 기존의 변수 a에 반환된 a값 덮어쓰기
	printf("Callee의 return값(을 저장한 변숫값 출력) : %d\n", a);

	return 0;
}

int add_ten(int a)	// 같은 메모리(stack) 영역이나 변수 a의 주소값이 다른 메모리 공간 사용
{
	a += 10;

	return a;
}
