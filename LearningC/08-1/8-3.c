#include<stdio.h>
#include<stdlib.h>	

int main(void)
{
	int score[5];
	int total = 0;
	double avg;
	int count, i;

	count = sizeof(score) / sizeof(score[i]) ; // 배열의 요소 개수가 고정이 아닐 경우를 대비해 배열 요소의 개수 계산을 하는 count (배열명( 총개수 -> 동적) 사이즈 / 배열 요소) 추가

	for(i = 0; i<count; i++)
	{
		scanf("%d", &score[i]);
	}

	for (i = 0; i < count; i++)  // 12행에서 개선한 count만큼 반복
	{
		total += score[i]; // total = total + score[i]
	}
	avg = total / (double)count; // 총합을 count로 나누어 평균 계산

	for ( i = 0; i < count; i++)
	{
		printf("%5d", score[i]);
	}

	printf("\n");


	printf("Average: %.1lf\n", avg);

	return 0;
}
