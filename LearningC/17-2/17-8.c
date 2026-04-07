#include <stdio.h>

struct address
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

void print_list(struct address *listpointer);  // 구조체 배열의 이름을 인수로 받는 함수는 구조체 포인터(주소값)를 매개변수로 선언

int main(void)
{
	struct address list[5] = {					// 요소가 5개인 배열 선언
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"이순신", 35, "111-1111", "울릉도 독도"},
		{"장보고", 19, "111-1111", "울릉도 독도"},
		{"유관순", 15, "111-1111", "울릉도 독도"},
		{"안중근", 45, "111-1111", "울릉도 독도"},
	};

	print_list(list);

	return 0;

}
void print_list(struct address *listpointer) // 매개변수는 구조체 변수 포인터
{
	int i, j;

	for (i=0; i < 5; i++)
	{
			printf("%10s%5d%15s%20s\n", 
				(listpointer+i)->name, (listpointer+i)->age, (listpointer+i)->tel, (listpointer+i)->addr);
	}
}