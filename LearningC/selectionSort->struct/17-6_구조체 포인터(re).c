# include <stdio.h>

struct score
{
	int kor;
	int eng;
	int math;
};

int main(void)
{
	struct score younggi = { 100, 100, 100 };
	struct score *ps = &younggi;

	printf("국어 : %d\n", ps -> kor);
	printf("영어 : %d\n", ps -> eng);
	printf("수학 : %d\n", ps -> math);

	return 0;
}