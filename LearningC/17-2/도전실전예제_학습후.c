#include <stdio.h>

struct reportCard
{
	int num;
	char name[20];
	int kor;
	int eng;
	int math;
	char grade;
};

int main()
{
	struct reportCard list[5] = {
		{315, "홍길동", 80, 75, 90, 0},
		{316, "이순신", 88, 92, 100, 0},	
		{317, "서하윤", 95, 99, 98, 0},	
		{318, "유관순", 84, 70, 72, 0},	
		{318, "박신혜", 60, 65, 40, 0},
	};

	printf("정렬 전 데이터... \n");
	int i, total;
	double avg;
	total = list[i].kor + list[i].eng + list[i].math;
	avg = total / 3.0;
	for (i = 0; i < 5; i++)
	{
		if (avg > 89.0) list[i].grade = 'A';
		if (avg > 79.0) list[i].grade = 'B';
		if (avg > 69.0) list[i].grade = 'C';
		else list[i].grade = 'F';
		printf("%10d %5s %10d %10d %10d %c\n", list[i].num, list[i].name, list[i].kor, list[i].eng, list[i].math, list[i].grade);
		
	}
	
	printf("정렬 후 데이터... \n");

	return 0;
}