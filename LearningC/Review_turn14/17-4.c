#include <stdio.h>
/* 구조체 변수 선언과 동시에 초기화 */
struct profile					// 구조체 선언

{
	int id;
	char name[30];
	double grade;
};

int main()
{
	struct profile s1 = { 20230704, "Seo Younggi", 4.125 }; // 구조체 변수 선언과 초기화 예시
	struct profile s2 = { 20260704, "Lee Yuni", 3.125 };
	struct profile s3 = { 19890705, "Kim YoungHee", 4.2 };
	
	printf("학번\t\t\t\t성명\t\t\t학점\n");
	printf("%10d %10s\t %.3lf\n", s1.id, s1.name, s1.grade);
	printf("%10d %10s\t %.3lf\n", s2.id, s2.name, s2.grade);
	printf("%10d %10s\t %.3lf\n", s3.id, s3.name, s3.grade);

	struct profile max; //	최고 학점을 저장할 구조체 변수
	
	max = s1; 			// s1을 최고 학점으로 가정 -> 멤버별로 복사하지 않고, 대입 연산으로 멤버들을 한번에 복사 가능!
	if (s2.grade > s1.grade) max = s2;
	if (s3.grade > s2.grade) max = s3;

	printf("학번 : %d\n", max.id);
	printf("성명 : %s\n", max.name);
	printf("학점 : %1lf\n", max.grade);




}
