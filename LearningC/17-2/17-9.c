#include <stdio.h>

struct selfReferencedList // 	자기 참조 구조체
{
	int num;			// 데이터를 저장하는 멤버
	struct selfReferencedList *next;	// 구조체 자신을 가리키는 포인터 멤버
};

int main(void)
{
	struct selfReferencedList a = {10, 0}, b = {20, 0}, c = {30, 0}; // 구조체 변수 초기화
	struct selfReferencedList *head = &a, *current;			// 헤드 포인터 초기화

	a.next = &b;								// a의 포인터 멤버가 b를 가리킴
	b.next = &c;								// b의 포인터 멤버가 c를 가리킴

	printf("head->num : %d\n", head->num); 		// head가 가리키는 a의 num 멤버 사용
	printf("head->next->num : %d\n", head->next->num); 		// head로 b의 num 멤버 사용

	printf("list all : ");
	current = head;					// 최초 current 포잍너가 a를 가리킴
	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

	return 0;

}
