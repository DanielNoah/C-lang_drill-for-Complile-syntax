#include <stdio.h>

struct Node {
	int value;
	struct Node* next;
};

void func(struct Node* node) // Node 구조체 자료형의 첫 번째 주소를 가리키는 포인터 변수 node에 n1주소값을 저장 (즉, node는 n1을 가리킴) 
{
	while(node != NULL && node->next != NULL)
	{
		int t = node->value; // t = 1
		node->value = node->next->value; // n1.value = 3
		node->next->value =  t; // n3.value = 1
		node = node->next->next; // node = &n2
	}

}




int main()
{
	struct Node n1 = {1, NULL}; // Node 구조체 자료형을 가진 n1 접근 변수 선언 및 초기화
	struct Node n2 = {2, NULL}; // Node 구조체 자료형을 가진 n2 접근 변수 선언 및 초기화
	struct Node n3 = {3, NULL}; // Node 구조체 자료형을 가진 n3 접근 변수 선언 및 초기화

	n1.next = &n3;	// n1을 통해 next 구조체 변수에 n3의 주소값 저장 (즉, n1.next는 n3를 가리킴)
	n3.next = &n2;  // n3을 통해 next 구조체 변수에 n2의 주소값 저장 (즉, n3.next는 n2를 가리킴)

	func(&n1); // func 함수에 n1 주소값을 인자로 주고 호출

	struct Node* current = &n1;

	while(current != NULL) // &n1 -> &n3 -> &n2 -> NULL
	{
		printf("%d", current->value); // n1.value 출력 (3) 
		current = current->next; // n3.value 출력 (1) 
								// 한 바퀴 돌고, n2.value 출력(2)
	}	
								// 312 출력 후 종료
	return 0;
}