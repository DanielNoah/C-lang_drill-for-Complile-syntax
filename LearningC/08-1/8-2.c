#include<stdio.h>
#include<stdlib.h>	

int main(void)
{
	int score[5];		// 다섯 과목의 성적을 입력할 int형 배열 선언 -> 배열요소의 개수 5개(고정)
	int i;				// 반복 제어 변수
	int total = 0;
	double avg;

	for (i=0; i < 5; i++) // i가 0부터 4(index 순서 n-1)까지 다섯 번 반복
	{
		scanf("%d", &score[i]); // 각 배열 요소에 성적 입력
	}

	for (i = 0; i < 5; i++)		/* 반복문의 제어변수에 배열의 인덱스 0부터 4까지 대입 */
	{
		total += score[i];		// 성적을 누적해 총점 계산
	}
	avg = total / 5.0;			// 평균 계산

	for (i = 0; i < 5; i++)
	{
		printf("%5d", score[i]);	// 성적 출력
	}
	printf("\n");

	printf("평균 : %.1lf\n", avg);	// 평균 출력	

	return 0;
}