#include <stdio.h>

int main(void)
{
	int a, b, tot;
	double avg;

	printf("두 과목의 점수 : ");
	scanf("%d %d", &a, &b);
	tot = a + b;
	avg = tot / 2.0;
	// 평균 계산, tot가 정수형이므로 나누는 값을 2.0과 같이 실수값으로 사용해야함.
	// 그렇지 않으면 피연산자가 모두 정수 값이므로 몫을 내림 계산함(예 : 77 78 -> 77.0).

	printf("평균 : %.1lf \n", avg);

	return 0;
}
