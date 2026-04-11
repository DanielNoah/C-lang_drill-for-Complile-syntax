#include <stdio.h>

typedef struct
{
	int num;
	char name[20];
	int kor, eng, math;
	int tot;
	double avg;
	char grade;
} ReportScore ;

// typedef struct reportScore ReportScore;

void input_data(ReportScore *prs); // 선언한 구조체 배열 주소를 받기위해 포인터 prs 매개변수 선언
void calc_data(ReportScore *prs);  // 총점과 평균 그리고 학점을 계산하기 위한 함수
void sort_data(ReportScore *prs);  // 정렬하기 위한 함수
void print_data(ReportScore *prs); // 출력 함수

int main(void)
{	
	ReportScore rs[5];  // 배열명 선언 
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
		printf("학번은 > ");
		scanf("%d", &prs -> num);
		printf("이름은 > ");
		scanf("%s", prs ->  name);
		printf("각 과목의 점수(국어, 영어, 수학)은 > ");
		scanf("%d %d %d", &prs -> kor, &prs -> eng, &prs -> math);
		prs++;
	}	
}

void calc_data(ReportScore *prs)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		prs->tot = prs->kor + prs->eng + prs->math;
		prs->avg = prs->tot / 3.0; 
		if (prs->avg >= 90) prs->grade = 'A';
		else if (prs->avg >= 80) prs->grade = 'B';
		else if (prs->avg >= 70) prs->grade = 'C';
		else prs->grade = 'F';
		prs++; 
	}
}


void sort_data(ReportScore *prs)
{
	int i, j;
	ReportScore tmp;
	int max;
	
	for(i = 0; i < 4; i++)
	{	
		max = i;
		for(j = i + 1; j < 5; j++)
		{
			if(prs[max].tot < prs[j].tot)
			{
				max = j;
			}
		}
		if(max != i)	// 앞의 첫 번째 학생의 총점이 두번째 학생의 총점보다 작을 때
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

	for(i = 0; i < 5; i++)
	{
		printf("%5d %7s %5d %5d %5d %5d %7.1lf %5c\n", 
			prs->num, prs->name, prs->kor, prs->eng, prs -> math, 
			prs->tot, prs->avg, prs->grade);
		prs++;
	}
}
