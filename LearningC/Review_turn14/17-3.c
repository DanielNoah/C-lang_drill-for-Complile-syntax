#include <stdio.h>

struct profile					// 신상명세 구조체 선언

{
	int age;
	double height;
};

struct student			// 학생 구조체 선언 블럭 내
{
	struct profile pf;	// profile 구조체를 학생 구조체의 멤버로 사용한다고 컴파일러에 인지
	int id;				
	double grade;	
};

int main()
{
	struct student s1;	// 학생 구조체 (멤버 접근) 변수 선언
	s1.pf.age = 17;
	s1.pf.height = 167.3;
	s1.id = 20231040;
	s1.grade = 3.7;
	
	printf("%d %.1lf %d %.1lf\n", s1.pf.age, s1.pf.height, s1.id, s1.grade);
}