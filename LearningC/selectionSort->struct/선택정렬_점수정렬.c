#include <stdio.h>
#include <string.h>
/* IELTS overall score 계산기 */
double avg(double tot); 

int main()
{
	double score[4];
	double tot;
	int i;

	for (i = 0; i < 4; i++)
	{
//		printf("input score: \n");
		scanf("%lf", &score[i]);
		tot += score[i];
	}

	double temp;
	int j;
	for (i = 0; i < 3; i++) // 총 비교 횟수(선택정렬 반복) '3회'면 4과목의 성적 대소비교 가능 <- 슈도(Pesudo) 코드 작성 시 횟수 확인
	{
		for (j = i + 1; j < 4; j++)	// 비교기준 i(첫 번째 배열 요소 인덱스와 동일)와 
		{							// 비교대상 j(위치가 고정되면 안되므로 두 번째 벼열 요소 1부터 증가시킬 수 있도록 i+1)
			if(score[i] < score[j]) // 의 3번 반복하기 위한 중첩 반복문 사용 
			{						// 로직 -> 비교대상 i(배열의 첫 번째 요소의 수)가 다음 요소의 수보다 적으면,
				temp = score[i];	// 임시 변수에 적은 수 대입 후,
				score[i] = score[j];// 첫 번째 요소 자리(i)에 큰 수 대입 후,
				score[j] = temp;	// 기존 큰 수 자리(j)에 적은 수 대입함.
			}
		}
	}

	double average;
	average = avg(tot);			// 평균 함수 호출 후 average 변수에 대입
	if(average >= 7.25 || average <= 7.625) average = 7.5; // average 변수 아이엘츠 소숫점 산출 방식에 맞춰서 올림 (7.5점 기준 -> .25 ~ .625 => .5로 산출하는 로직은 다음에...) 
	printf("IELTS each 성적 :\n");
	for (i = 0; i < 4; i++)
	{
		printf("%.1lf\n", score[i]);
	}
	printf("Total / Overall : %.1lf %.1lf\n", tot, average);


		return 0;
}

double avg(double tot)
{
	return tot / 4.0;
}