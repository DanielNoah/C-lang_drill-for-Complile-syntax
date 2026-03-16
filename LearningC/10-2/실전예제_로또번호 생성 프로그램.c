#include <stdio.h>
#include <string.h>

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
	int i, j;
	int dup;
	int num;
	for(i = 0; i < 6; i++)
	{
		printf("번호 입력 : ");
		scanf("\n%d ", &num);
		dup = 0;
		for(j = 0; j < i; j++)
		{
			if(num == lotto_nums[j])
			{
				dup = 1;
				break;
			}
		}
		if (!dup)
		{
			lotto_nums[i] = num;
		}
		else
		{
			printf("같은 번호가 있습니다.");
			i--;
		}
	}
}

void print_nums(int *lotto_nums)
{
	int i;

	printf("로또 번호 :" );
	for(i = 0; i < 6; i++)
	{
		printf("%d ", lotto_nums[i]);
	}
}


