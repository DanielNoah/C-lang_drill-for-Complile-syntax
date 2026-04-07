#include <stdio.h>

struct reseacher
{
	int num;			// 데이터를 저장하는 멤버
	char level[2];
};
typedef struct reseacher Reseacher;		// Researcher형으로 재정의 (보통 일반변수명과 구분하기 위해 첫글자 대문자로 사용)
void print_data(Reseacher *pr); 		// 매개변수는 Researcher형의 포인터

int main(void)
{
	Reseacher younggi = { 2010, "S+"};

	print_data(&younggi);

	return 0;
}

void print_data(Reseacher *pr)
{
	printf("연번 : %d\n", pr->num);
	printf("수준 : %s\n", pr->level);
}
