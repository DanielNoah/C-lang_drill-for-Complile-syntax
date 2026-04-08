#include <stdio.h>

struct reportScore
{
	int num;
	char name[20];
	int kor, eng, math;
	int tot;
	double avg;
	char grade;
};

typedef struct reportScore ReportScore;

void input_data(ReportScore *prs); // 선언한 구조체 배열 주소를 받기위해 포인터 prs 매개변수 선언
void calc_data(ReportScore *prs);  // 총점과 평균 그리고 학점을 계산하기 위한 함수
void sort_data(ReportScore *prs);  // 정렬하기 위한 함수
void print_data(ReportScore *prs); // 출력 함수

int main(void)
{	
	ReportScore rs[5];
//	input_data(&rs[0], &rs[1], &rs[2], &rs[3], &rs[4]);	// 문자열배열 기초 -> 첫번째 배열 요소 출력 시 배열요소 모두 출력
	
	input_data(rs);
	calc_data(rs);
	printf("정렬 전 데이터...\n");
	print_data(rs);
	sort_data(rs);
	printf("정렬 후 데이터...\n");
	print_data(rs);
	
	return 0;
}

void input_data(ReportScore *prs)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("학번 : ");	
		scanf("%d", &prs->num); // 주소연산자를 구조체 변수에 입력해야(캐릭터 문자열 제외)
		printf("이름 : ");
		scanf("%s", prs->name);
		printf("국어, 영어, 수학 점수 : ");	
		scanf("%d %d %d", &prs->kor, &prs->eng, &prs->math);
		prs++;
	}

}

void calc_data(ReportScore *prs)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		prs->tot = prs->kor + prs->eng + prs->math;
		prs->avg = prs->tot / 3.0;
		if (prs->avg >= 90.0) prs->grade = 'A';
		else if (prs->avg >= 80.0) prs->grade = 'B';
		else if (prs->avg >= 70.0) prs->grade = 'C';
		else prs->grade = 'F';
		prs++; // 구조체 배열 offset(한 행)+1 씩 이동하면서 각 학생별 성적 산출해야하므로
	}
}

void sort_data(ReportScore *prs){
//	int tmp, i, j; // 임시변수는 구조체 배열형과 동일한 형 선언해야...
	ReportScore tmp;
	int i, j, max;

	for(i = 0; i < 4; i++) // 총 '4회' 대소 비교해야 함(다섯명의 학생 총점 비교).
	{
		max = i; // 첫 번째 총점 배열 요소를 가장 크다고 가정.
		for(j = i + 1; j < 5; j++) 
			{
				if (prs[max].tot < prs[j].tot)
				{
					max = j;
				}
			}
			if (max != i)
			{
				tmp = prs[max];
				prs[max] = prs[i];
				prs[i] = tmp;
			}
	}
}

void print_data(ReportScore *prs)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%5d %7s %5d %5d %5d %5d %7.1lf %5c\n", 
			prs->num, prs->name, prs->kor, prs->eng, 
			prs->math, prs->tot, prs->avg, prs->grade);
		prs++; // 구조체 배열 offset(한 행)+1 씩 이동하면서 각 학생별 성적 산출해야하므로
	}
}

