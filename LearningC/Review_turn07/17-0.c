#include <stdio.h>

struct student	// 구조체 선언
{
	int num;	// 서로 다른 데이터 타입의 멤버 선언
	char name;
	double grade;
};				// 세미콜론 사용
/*	struct student = {char name; char class; int score;}; <- 구조체와 멤버를 한 번에 선언할 경우 */


int main(void)
{
	struct student s1; // struct student형의 변수 선언 (구조체 멤버에 접근하기 위한 변수) 
						/* 결국, '사용자가 정의한 새로운 자료형'을 컴파일러에게 통보하는 것임. */

	s1.num = 2;			// s1의 num 멤버에 2 저장
	s1.grade = 2.7;		// s1의 grade 멤버에 2.7 저장
	printf("학번 : %d\n", s1.num);	// num 멤버 출력
	printf("학점 : %.1lf\n", s1.grade);	// grade 멤버 출력

	return 0;


}
