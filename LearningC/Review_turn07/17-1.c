#include <stdio.h>

struct student{
	int num;
	double grade;
};

int main(void)
{
	struct student s1;
	s1.num = 10;
	s1.grade = 4.5;

	printf("%d\n", s1.num);
	printf("%.1lf\n", s1.grade);

}