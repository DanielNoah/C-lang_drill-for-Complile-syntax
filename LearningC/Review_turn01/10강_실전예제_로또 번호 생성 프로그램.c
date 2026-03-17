#include <stdio.h>

void input_nums(int *lotto_nums);  // 배열에 로또 번호를 입력하는 함수
void print_nums(int *lotto_nums);  // 배열에 저장된 값을 출력하는 함수 

int main(void)

{
     int lotto_nums[6];            // 로또 번호를 저장할 배열

     input_nums(lotto_nums);       // 입력함수 호출
     print_nums(lotto_nums);       // 출력함수 호출
     return 0;
}

void input_nums(int *lotto_nums)
{
     int num;
     int i, j;
     int dup;

     for(i=0; i<6; i++)
     {
          printf("번호 입력 : \t");
          scanf("%d", &num);
          dup = 0;
          for(j=0; j<i; j++)
          {     
               if(num == lotto_nums[j])
               {
/*                  lotto_nums[i] = num; // 여기서 로또 번호 대입을 하는 게 아니라, 중복인 값을 판별하는 조건식 넣어야 함. */ 
                    dup = 1;
                    break;
               }
          }
          if(!dup)
          {
               lotto_nums[i] = num;
/*             --i;  // 중복된 값이므로 전체 for문 한 바퀴 더 돌도록(중복일 경우) 제어변수 i를 1 감소 시킴(증감연산자 확인할 것!). */
          }
          else
          {
               printf("같은 번호가 있습니다!");
               i--;
          }
     }
}

void print_nums(int *lotto_nums)
{
     int i;

     printf("로또 번호 : ");
     for(i=0; i<6; i++)
     {
          printf("%d ", lotto_nums[i]);
     }

}
