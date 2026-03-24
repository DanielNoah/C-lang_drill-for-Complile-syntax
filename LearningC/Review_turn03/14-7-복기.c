#include <stdio.h>

int main(void)
{
    int ary1[4] = {1,2,3,4};
    int ary2[4] = {11,12,13,14};
    int ary3[4] = {21,22,23,24};
    int *pary[3] = {ary1, ary2, ary3};

    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
             printf("%5d", pary[i][j]);
        }   
        printf("\n");
    }
    printf("%5d", pary[2][2]);      // pary[2]도 배열명을 저장한 포인터이므로, ary3과 같이 배열명 사용 가능
                                    // pary[2]를 배열명처럼 사용(pary의 인덱스 0,1,2(3행))해 ary3 배열의 세 번째 요소를 다음과 같이 사용가능.
    return 0;

}0