#include <stdio.h>

struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

int main(void)
{
	struct address list[5] = {
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "111-1111", "울릉도 독도"},
		{"장보고", 19, "111-1111", "울릉도 독도"},
		{"유관순", 15, "111-1111", "울릉도 독도"},
		{"안중근", 45, "111-1111", "울릉도 독도"},
	};

	int i;

	for (i=0; i < 5; i++)
	{
		printf("%10s%5d%15s%20s\n", 
			list[i].name, list[i].age, list[i].tel, list[i].addr);
	}
	

	return 0;
}