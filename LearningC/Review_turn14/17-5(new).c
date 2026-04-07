#include <stdio.h>
/* 구조체를 반환해 두 변수의 값 교환 */

struct vision					// 구조체 선언

{
	double left;
	double right;
};

struct vision exchange(struct vision robot); // 교환 함수 프로토타입 선언

int main()
{
//	struct vision robot = {20.0, 20.0}; // 구조체 변수 robot의 값을 입력받는 걸로 코드 수정
	struct vision robot;

	printf("시력 입력 : \n");
	scanf("%lf %lf", &robot.left, &robot.right);  // 입력 문자열 형식 주의할 것.(.1lf X -> lf 더블형 사용)
	
	robot = exchange(robot); 			// 교환함수에 robot(멤버 접근 변수)의 값을 인수로 전달 (함수 호출)

	printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);

	return 0;
}

struct vision exchange(struct vision robot)
{
	double tmp;

	tmp = robot.left;
	robot.left = robot.right;
	robot.right = tmp;

	return robot;

}
