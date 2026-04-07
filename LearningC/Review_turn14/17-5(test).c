#include <stdio.h>
/* 구조체를 반환해 두 변수의 값 교환 */

struct vision{
	double left, right;
};

struct vision exchangeVision(struct vision robot);

int main(void)
{
	struct vision robot;

	printf("시력 입력 : \n");
	scanf("%lf %lf", &(robot.left), &(robot.right));

	robot = exchangeVision(robot);

	printf("바뀐 시력 : %.1lf %.1lf", robot.left, robot.right);

	return 0;
}

struct vision exchangeVision(struct vision robot)
{
	double temp;
	
	temp = robot.left;
	robot.left = robot.right;
	robot.right = temp;

	return robot;

}
