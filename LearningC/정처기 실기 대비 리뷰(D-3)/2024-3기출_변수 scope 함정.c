#include <stdio.h>

int func()
{
	static int x = 0;	// 실행 간 값 유지
	x += 2;				// x = x + 2;
	return x;			// 반환값 순서 2 -> 4 -> 6 -> 8
}

int main()
{
	int x = 1;
	int sum = 0;
	for(int i = 0; i < 4; i++)	// '4회' 반복
	{
		x++;			// x=1
		sum+=func();	// sum = sum + func() -> sum = 0 + 반환값
						// sum 누적값 순서 2 -> 6 -> 12 -> 20 (출력값)
	}
	printf("%d", sum);

	return 0;
}