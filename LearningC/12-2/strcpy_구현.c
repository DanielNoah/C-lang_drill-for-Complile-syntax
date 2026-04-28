#include <stdio.h>

void myStrcpy(char*, char*); //매개변수명은 생략가능함.
char* internal_strcpy(char *pd, char *ps);

int main()
{
	char str1[] = "buffer";
	char str2[] = "overflowed";

	printf("초기 str1 : %s \n초기 str2 : %s\n\n", str1, str2);

	myStrcpy(str1, str2);
	printf("1) str1에 str2를 복사(덮어쓰기) : %s\n\n", str1);

	internal_strcpy(str1, "apple");	// 문자열 "apple" 복사
	printf("2) 새로운 문자열을 str1에 복사 : %s\n\n", str1);
	
	// 반환값으로 출력
	printf("3) 다른 문자열 대입 : %s\n\n", internal_strcpy(str1, "Macbook M4"));

// str1 = str2; // 배열명은 배열의 첫 번째 요소 주소 값(l-value)을 가리키므로, 
// 상수 = 상수 (X)

	return 0;
}

void myStrcpy(char* pa, char* pb)
{
	// pa = pb; // 포인터 변수 pa에 pb 포인터의 주소값을 대입하므로,  
	// pa의 주소값이 pb를 향하지만, myStrcpy 함수 로컬 변수이므로 
	// main()에서 호출 시 값의 복사(교환)가 안됨.
		
	while (*pb)
	{
		*pa = *pb; 
		pa++;
		pb++;
	}
	*pa = '\0';

}

/* strcpy 실제 내부구조 */
char* internal_strcpy(char *pd, char *ps)	// 복사 받을 곳(pd)과 복사할 곳(ps)의 포인터
{
	char *po = pd; 	// pd 값을 나중에 반환하기 위해 보관

	while (*ps != '\0') // ps가 가리키는 문자가 널 문자가 아닌 동안
	{
		*pd = *ps;		// ps가 가리키는 문자를 pd가 가리키는 위치에 대입
		pd++;			// 복사 받을 다음 위치로 포인터 증가
		ps++;			// 복사할 다음 문자의 위치로 포인터 증가
	}
	*pd = '\0';			// 복사가 모두 끝난 후 복사 받을 곳에 널 문자로 마무리
	
	return po;			// 복사가 끝난 저장 공간의 시작 주소 반환
}
