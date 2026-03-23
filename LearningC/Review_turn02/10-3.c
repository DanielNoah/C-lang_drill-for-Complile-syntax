#include <stdio.h>

int main(void)
{
	int ary[3] = { 10, 20, 30 };
	int *pa = ary;
	int i;

	printf("배열의 값 : ");
	for (i = 0; i < 3; i++)
	{	
	/*	scanf("%d", pa); <- pa가 가리키는 배열 요소에 입력, 간접 참조 연산 없음.
		pa++;	<- 다음 배열 요소를 가리키도록 pa 증가*/ 
	    
		printf("%d ", *(++pa));;
	/*	pa++; */
	}
	// for문 전부 돌고 난 뒤에 15행의 
	// pa값은 112번지(인덱스 3)가 됨. 이 값은 배열이 할당된 영역의 주소가 아니므로,
	// 간접 참조 연산을 통해 그 공간이나 저장된 값을 사용해서는 안됨.
	return 0;
}