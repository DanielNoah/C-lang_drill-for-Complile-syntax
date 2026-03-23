#include <stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

int main(void)
{	
	int lotto_nums[6];

	input_nums(lotto_nums);
	print_nums(lotto_nums);
	return 0;
}

void input_nums(int *lotto_nums)
{
	int num;
	int i, j;
	int dup;				// 위치 반복문 시작 전! (but,flag 변수 선언 후, 활용을 못함.)

	for(i = 0; i < 6; i++)		//	>전체 흐름<
	{							//  Flag(상태) 변수를 통해서 먼저 중복인 상태를 default로 해서 빠져나가서, 중복 조건문(if~else)를 통해 분기
		printf("번호 입력 :\n");
		scanf("%d", &num);
	
		dup = 0;				// 상태 변수 초기화 해야함.(기본 값 0(false))
		for(j = 0; j < i; j++)
		{
		//	if(lotto_nums[i] != lotto_nums[j])		// 조건식 비교연산의 변수 잘못설정 -> lotto_num[i] -> num
			if(num == lotto_nums[j])
			{
			//	lotto_nums[i] = num;	// 오류 포인트. -> 여기서는 flag 변수 상태만 변화시킴. 
				dup = 1; 				// 제어변수 상태(true -> 중복일 경우)
				break;
			}
		}
		if(!dup)					// 제어변수 상태(false -> 중복이 아닐 경우)
		{
			lotto_nums[i] = num;			
		}
		else
		{
			printf( "같은 번호가 있습니다!");
			i--;						// num의 값을 로또번호 배열에 대입시킨 후, 한 번 ㅐ 로또 번호(num) 입력시키기 위해 제어변수 i 감소 연산
		}
	}
}		


void print_nums(int *lotto_nums)
{
	int i;
	printf("로또 번호 : ");
	for(i = 0; i < 6; i++)
	{
		printf("%d\t", lotto_nums[i]);		
	}	 
}
