#include <stdio.h>

struct student			// 구조체 선언을 통해 컴파일ㄹ러에 미리 구조체의 형태를 알려야함
{
	int num;
	double grade;
};

int main()
{
	struct student s1; // struct student형의 변수 선언

	s1.num = 20241040;
	s1.grade = 3.1;
	printf("학번 : %d\n", s1.num);
	printf("학점 : %.1lf\n", s1.grade);

	return 0;
}


