#include <stdio.h>

int main(void)
{
	unsigned char data = 255;	// getchar()가 파일로부터 읽은 데이터
	int res;					// getchar()가 반환할 데이터
	int ch;						// 반환값을 저장할 변수 -> int (4-byte)

	res = data;					// getchar()가 파일로부터 읽은 데이터를 int형 변수에 대입 후 반환
	printf("반환된 데이터의 값 : %d\n", res);

	ch = res;					// 반환 값(int형)을 char 변수에 대입

	if (ch == -1)
		printf("반환값 255가 -1과 같다!\n"); 
	/* 왜? 대입하는 변수의 데이터타입(signed char, 1111 1111)이 저장하는 데이터(unsigned char)가
		  저장할 때 꽉차서 부호비트(->1 111 1111)를 마이너스로 인식하기 때문에! */
	else
		printf("반환값 255는 -1이 아니다.\n");
	/* 대입하는 변수의 데이터 타입(int, 4-byte)이므로, 저장하는 데이터의 크기(1byte)보다 크므로
		저장할 때 부호비트(->0 000 0000 ... 1111 1111)를 플러스로 인식하기 때문에, data의
		값 255를 그대로 출력함. */

	return 0;
}