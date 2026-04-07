#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct profile

{
	char name[20];
	int age;
	double height;
	char *intro;
};

int main(void)
{
	struct profile yuni;

	strcpy(yuni.name, "Seo Yuni");
	yuni.age = 17;
	yuni.height = 168;
	yuni.intro = (char*)malloc(80);

	printf("Introduction: \n");
	gets(yuni.intro);

	printf("이름 : %s\n", yuni.name);
	printf("나이 : %d\n", yuni.age);
	printf("신장 : %1lf\n", yuni.height);
	printf("소개 : %s\n", yuni.intro);

	return 0;
}