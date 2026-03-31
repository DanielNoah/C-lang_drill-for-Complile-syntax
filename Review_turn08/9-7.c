#include <stdio.h>

void swap(int *pa, int *pb);

int main()					// 메모리 스택 영역에 할당
{
	int a = 10, b = 20;

	swap(&a, &b);
	printf("%d, %d\n", a, b);

	return 0;
}

void swap(int *pa, int *pb) // 메모리 swap 영역에 할당
{
	int temp;	// 교환을 위한 임시 변수

//	temp = pa;  //pa, pb는 포인터변수로 l-value로 쓰이면, 가리키는 변수의 첫 번째 주소 값을 의미함.
//	pa = pb;	//*pa, *pb처럼 *(간접참조 연산자)를 사용해서 가리키는 변수의 저장값을 교환(swap)시킴. 
//	pb = temp;

	temp = *pa;	// temp에 pa가 가리키는 변수의 값 저장
	*pa = *pb;	// pa가 가리키는 변수에 pb가 가리키는 변수의 값 저장
	*pb = temp; // pb가 가리키는 변수에 temp 변수(pa가 가리키는 값)의 값 저장	
}
