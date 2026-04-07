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
	struct reportCard s1 = {315, "홍길동", 80, 75, 90, 0};
	struct reportCard s2 = {316, "이순신", 88, 92, 100, 0};	
	struct reportCard s3 = {317, "서하윤", 95, 99, 98, 0};	
	struct reportCard s4 = {318, "유관순", 84, 70, 72, 0};	
	struct reportCard s5 = {318, "박신혜", 60, 65, 40, 0};

	
	if (((s1.kor + s1.eng + s1.math) / 3) > 89) s1.grade = 'A';
	if (((s1.kor + s1.eng + s1.math) / 3) > 79) s1.grade = 'B';
	if (((s1.kor + s1.eng + s1.math) / 3) > 69) s1.grade = 'C';
	else s1.grade = 'F';


	printf("정렬 전 데이터... \n");
	printf("%d %s %d %d %d %c\n", s1.num, s1.name, s1.kor, s1.eng, s1.math, s1.grade);
	printf("%d %s %d %d %d %c\n", s1.num, s1.name, s1.kor, s1.eng, s1.math, s1.grade);
	printf("%d %s %d %d %d %c\n", s1.num, s1.name, s1.kor, s1.eng, s1.math, s1.grade);
	printf("%d %s %d %d %d %c\n", s1.num, s1.name, s1.kor, s1.eng, s1.math, s1.grade);
	
	printf("정렬 후 데이터... \n");

	return 0;
}