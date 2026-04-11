#include <stdio.h>

typedef struct 
{
	int num;
	char name[20];
	int eng, c, mat;
	int tot;
	double avg;
	char grade;
} Student;

void input_data(Student* pary);
void calc_data(Student* pary);
void sort_data(Student* pary);
void print_data(Student* pary);


int main()
{
	Student ary[5]; // 구조체 배열 초기화 (학생 5명에 대한 구조체 배열)

	input_data(ary);
	calc_data(ary);
	
	printf("정렬 전 데이터 :\n");
	print_data(ary);
	sort_data(ary);
	printf("정렬 후 데이터 :\n");
	print_data(ary);

	return 0;

}

void input_data(Student* pary)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("학번 :");
		scanf("%d", &pary->num);
		printf("이름 :");
		scanf("%s", pary->name);
		printf("영어 / C언어 / 수학의 점수 :");
		scanf("%d %d %d", &pary->eng, &pary->c, &pary->mat);
		pary++; 
	}
}

void calc_data(Student* pary)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		pary->tot = pary->eng + pary->c + pary->mat;
		pary->avg = pary->tot / 3.0;
		
		if(pary->avg >= 90) pary->grade = 'A';
		else if (pary->avg >= 80) pary->grade = 'B';
		else if (pary->avg >= 70) pary->grade = 'C';
		else pary->grade = 'F';
		pary++; // <-구조체 배열 offset(한 행)+1 씩 이동하면서 각 학생별 성적 산출해야하므로
	}
}

void sort_data(Student* pary)
{
	int i, j;
	Student temp;
	int max;

	for(i = 0; i < 4; i++)
	{
		max = i;
		for(j = i+1; j < 5; j++)
		{
			if(pary[max].tot < pary[j].tot) // 기존 pary[i].tot > pary[j].tot
			{
				max = j;
			} 	
		}
		if(max != i)	// 기존 i != max
		{
			temp = pary[max]; // 기존 temp.tot = pary[i].tot;
			pary[max] = pary[i]; // max = pary[j].tot;
			pary[i] = temp; // 기존 pary[j].tot = pary[i].tot;
		}
	}
}

void print_data(Student* pary)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("No. : %5d 이름 : %7s영어 : %5d C언어 : %5d 수학 : %5d 총점 : %5d 평균 : %5.1lf\n", 
			pary->num, pary->name, pary->eng, pary->c, pary->mat, pary->tot, pary->avg);
		pary++;
	}
}