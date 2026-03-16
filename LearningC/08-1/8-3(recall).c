#include <stdio.h>

int main()
{
	int score[5];
	int i;
	int total = 0;
	double avg;
	int count;

	count = sizeof(score) / sizeof(score[0]); // 배열요소의 개수 계산

	for (i = 0; i < count; i++) // 11행에서 계산한 count만큼 반복
	{
		scanf("%d", &score[i]);
	}

	for (i = 0; i < count; i++)
	{
		total += score[i];
	}
	avg = total / (double)count; // avg 변수는 double로 선언했기 때문에 총합에 double형으로 캐스팅한 count를 나누어 평균 계산

	for (i = 0; i < count; i++)
	{
		printf("%5d", score[i]);
	}
	printf("\n");

	printf("평균 : %.1lf", avg);

	return 0;
}