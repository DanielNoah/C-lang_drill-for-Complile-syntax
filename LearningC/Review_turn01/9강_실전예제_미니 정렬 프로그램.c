#include <stdio.h>

void swap(double *pa, double *pb);
void line_up(double *maxp, double *midp, double *minp);

int main(void)
{
	double max, mid, min;

	printf("실수값 3개 입력 : \n");
	scanf("\n%lf %lf %lf", &max, &mid, &min);
	line_up(&max, &mid, &min);				// 세 변수의 값을 정렬하는 함수 호출
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);


	return 0;
}
void swap(double *pa, double *pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;

}
void line_up(double *maxp, double *midp, double *minp)
{ 
	if(*maxp < *minp){ swap(minp, maxp); } // swap함수 호출 시 매개변수 *pa에 minp(min 변수 가리키는 첫 번째 주소값)을 인수로 패싱, 마찬가지로 maxp를 인수로 패싱
	if(*maxp < *midp){ swap(midp, maxp); } // swap함수 호출 시 매개변수 *pa에 midp(min 변수 가리키는 첫 번째 주소값)을 인수로 패싱, 상동
	if(*midp < *minp){ swap(minp, midp); } // swap함수 호출 시 매개변수 *pa에 minp(min 변수 가리키는 첫 번째 주소값)을 인수로 패싱, 마찬가지로 midp를 인수로 패싱
}