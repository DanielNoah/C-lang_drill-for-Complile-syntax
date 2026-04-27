#include <unistd.h> // read() 함수를 위해 필요
#include <stdio.h> // printf() 함수를 위해 필요

int my_getchar(void);

int main()
{
    char ch;

    while (ch != '\n')
    {
        ch = my_getchar();
        
        /* 만약 unsigned int형 (32bit 시스템 기준 4byte 크기, 0 ~ 429496725)을 
         * 사용 시, 큰 양수를 저장하고 %d로 출력하면 음수가 출력되거나,
         * 음수를 저장하고 %u로 출력하면 양수가 출력될 수도 있으므로,
         * 항상 양수만 저장하고, %u로 출력하기를 권고함. */

        // unsigne char형은 ASCII 256
        printf("%c", ch);
    }
    printf("\n");
    
    return 0;    
}
int my_getchar(void) {
    unsigned char ch;   
    // 0번(stdin)에서 1바이트를 읽어 ch에 저장
    if (read(0, &ch, 1) == 1) {
        return (int)ch;
    }
    return -1; // EOF (End of File) 
}
/* UNIX(macOS 포함) 계열 시스템에서는 read라는 시스템 콜을 사용합니다. 
 * 파일 디스크립터 0번(표준 입력, stdin)에서 1바이트를 읽어오는 방식입니다.*/