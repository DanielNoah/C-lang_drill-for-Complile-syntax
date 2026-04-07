#include <stdio.h>
#include <string.h>

struct book
{
	char title[20];
	char author[20];
	int page;
	double price;
};

int main()
{
	struct book a; // 멤버를 독립된 변수로 사용 가능하게 하는 멤버 접근 변수 a 선언
//	a.title = "1982";	// 배열명은 주소상수이므로 대입연산자 왼편(l-value)에 올 수 없음.
	strcpy(a.title, "1982");
//	a.author = "Georgi Owell"; // 상동
	strcpy(a.author, "Georgi Owell");
	a.page = 430;
	a.price = 1.3;

	printf("%s %s %d %1lf\n",a.title, a.author, a.page, a.price);
}