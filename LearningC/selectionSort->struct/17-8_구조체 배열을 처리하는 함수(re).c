#include <stdio.h>

struct address								// 주소록을 만들 구조체 선언
{
	char name[20];
	int age;
	char tel[20];
	char addr[80];
};

void print_list(struct address *lp);

int main()
{
	struct address ary[5] = {					// 요소가 5개인 구조체 배열 선언
		{"홍길동", 23, "111-1111", "울릉도 독도"},
		{"유관순", 20, "222-2222", "서울 건천동"},
		{"장보고", 30, "333-3333", "완도 청해진"},
		{"서재필", 50, "444-4444", "서울 연희동"},
		{"서영기", 33, "555-5555", "경기도 의왕시"}
	};											// 구조체 배열을 '선언'했기 때문에 ; 
	
	print_list(ary);

	return 0;
}

void print_list(struct address *lp)
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("%10s%5d%15s%25s\n",
			(lp+i) -> name, (lp+i) -> age, (lp+i) -> tel, (lp+i) -> addr);
	}

}