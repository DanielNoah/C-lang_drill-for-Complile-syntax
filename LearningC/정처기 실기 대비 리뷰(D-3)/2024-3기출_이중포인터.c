#include <stdio.h>

void array(int** arr, int size) // arr(매개 변수)에 pp의 값(주소값 p)을 대입해서 결국 arr은 &p를 가리킴. 
{
	for(int i = 0; i < size; i++)	// size = 5 만큼 5회 반복
	{
		*(*arr + i) = (*(*arr + i) + i) % size; // arr의 첫번째 주소값(arr[0])에서 인덱스 i(자료형 크기)만큼 증가한 배열 arr를 가리키는 포인터 변수에
											// *arr+i이 가리키는 배열의 값에 i를 더한 뒤 size(5)를 mod 시킴(나머지 값)
										// 대입값 순서 (i = 0, 1, 2, 3, 4)
										// *(*arr + i) = 3, 2, 1, 4, 4 -> arr[] = {3, 2, 1, 4, 4} 로 값이 덮어씌어짐.
	}
}

int main()
{
	int arr[] = {3, 1, 4, 1, 5}; // 배열 arr 선언과 초기화
	int* p = arr;				// 배열 arr를 가리키는 포인터 p 선언과 초기화
	int** pp = &p;				// 포인터 p를 가리키는 이중 포인터 pp 선언과 초기화
	int num = 10;				

	array(pp, 5);				// array()함수에 pp, 5를 인수로 주고 호출
	num = arr[2];				// num에 포인터 변수와 동일한 arr[2]의 덮어씌어진 값 대입
	printf("%d", num);			// 정수형 값 num 출력 -> arr[2] = 1

	return 0;
}