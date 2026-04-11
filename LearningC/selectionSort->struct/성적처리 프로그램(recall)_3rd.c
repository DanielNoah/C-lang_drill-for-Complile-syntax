#include <stdio.h>

typedef struct
{
	int num;
	char name[20];
	int clang, python, java;
	int tot;
	double avg;
	char grade;
} Student;

void inputData(Student* pary);
void printData(Student* pary);
void calcData(Student* pary);
void sortData(Student* pary);

int main()
{
	Student ary[5]; // Student 구조체형을 가지는 다섯 개의 배열요소 ary 선언
	inputData(ary);

	printf("정렬 전 데이터 ... \n");
	calcData(ary);		// 누락함!
	printData(ary);
//	calcData(ary);			// <- calcData함수는 정렬 전에도 호출되어야 함.
	sortData(ary);
	
	printf("정렬 후 데이터 ... \n");
	printData(ary);

	return 0;
}

void inputData(Student* pary)
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("번호 :\n");
		scanf("%d", &pary->num);
		printf("이름 :\n");
		scanf("%s", pary->name);
	
		printf("C언어 / 파이썬 / 자바 성적 :\n");
		scanf("%d%d%d", &pary->clang, &pary->python, &pary->java);
		pary++;
	}
}

void printData(Student* pary)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		printf("	번호	 이름	  C언어  파이썬  자바  총점	평균	 학점\n");
		printf("%5d %5s %5d %5d %5d %5d %5.1lf %3c\n",
		 pary->num, pary->name, pary->clang, pary->python, pary->java,
		 pary->tot, pary->avg, pary->grade);
		pary++;
	}
}

void calcData(Student* pary)
{
	int i;
	for(i = 0; i < 5; i++)
	{
		pary->tot = pary->clang + pary->python + pary->java;
		pary->avg = pary->tot / 3.0;
		if (pary->avg >= 90.0) pary->grade = 'A';
		else if (pary->avg >= 80.0) pary->grade = 'B';
		else if (pary->avg >= 70.0) pary->grade = 'C';
		else pary->grade = 'F';
		pary++;
	}
}

void sortData(Student* pary)
{
	int i, j, maxIdx;
	Student tmp;
	for(i = 0; i < 4; i++)
	{
		maxIdx = i;  // <- pary[i].tot;
		for(j = 1 + i; j < 5; j++)
		{
			if (pary[maxIdx].tot < pary[j].tot) // <- 로직 생각 못함!
			{
				maxIdx = j; // <- pary[j].tot;
			}
		}				
	//	if(i != maxIdx) // <- (pary[i].tot != pary[maxIdx].tot) <- 없어도 되는 조건...
		{
			tmp = pary[maxIdx]; // <- pary[i];
			pary[maxIdx] = pary[i]; // <- pary[i] = pary[maxIdx];
			pary[i] = tmp; // <- pary[maxIdx] = pary[i]
		}
	}
}
