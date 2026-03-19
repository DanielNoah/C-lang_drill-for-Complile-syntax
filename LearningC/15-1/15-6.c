#include <stdio.h>

void print_ary(int (*)[4]);

int main(void)
{
	int ary[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

	print_ary(ary);				// 배열명을 인수로 주고 함수 호출

	return 0;
}

void print_ary(int (*pa)[4])
{
	int i, j;

	for (i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%5d", pa[i][j]);
		}
		printf("\n");
	}
}

/* 
2차원 배열 int ary[3][4]; 에서 다음 주소는 모두 같은 값을 가짐
1) &ary 	// 2차원 배열 전체의 주소
2) ary  	// 첫 번째 부분 배열의 주소
3) &ary[0]  // 첫 번째 부분배열의 주소
4) ary[0]   // 첫 번째 부분배열의 첫 번째 배열 요소의 주소
5) &ary[0][0] // 첫 번째 부분배열의 첫 번째 배열 요소의 주소

배열은 주소 뿐 아니라, 논리적으로 변수의 기능도 함. 따라서 sizeof 연산 수행하면 크기가 서로 다름 
1) sizeof(ary) 		// 배열 전체의 크기 96 byte (x64 아키텍처 기준 포인터 변수가 8byte 가정)
2) sizeof(&ary[0])  // 주소의 크기 8 byte
3) sizeof(ary[0])   // 부분배열 전체의 크기 32 byte
4) sizeof(&ary[0][0]) // 주소의 크기 4 byte
*/ 
