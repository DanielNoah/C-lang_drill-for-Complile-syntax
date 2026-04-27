#include <stdio.h>

// 시스템 콜을 직접 호출하는 나만의 read 함수
long my_read(int fd, void *buf, size_t count) {
    long ret;
    // syscall을 호출하여 rax(번호), rdi(인자1), rsi(인자2), rdx(인자3)를 세팅
    __asm__ volatile (
        "syscall"
        : "=a" (ret)                    // 출력: rax 값을 ret에 저장
        : "0" (0), "D" (fd), "S" (buf), "d" (count) // 입력: rax=0, rdi, rsi, rdx
        : "rcx", "r11", "memory"        // 시스템 콜 호출 시 파괴되는 레지스터들
    );
    return ret;
}

int main() {
    char ch;
    printf("입력 대기중: ");
    fflush(stdout);

    // 우리가 만든 my_read 사용
    my_read(0, &ch, 1);

    printf("\n읽은 문자: %c\n", ch);
    return 0;
}

/* 커널 내부에서는 어떤 일이 일어날까?
 * syscall 명령어가 실행되면 CPU는 유저 모드를 멈추고 커널 모드로 진입합니다.
 * Syscall Handler: 커널은 rax 값이 0인 것을 보고 "아, read 요청이구나"라고 판단합니다.
 * VFS (Virtual File System): 파일 디스크립터(0번)가 터미널인지, 파일인지 확인합니다.
 * Driver: 터미널 드라이버에게 데이터를 요청합니다. 사용자가 키보드를 치고 엔터를 누를 때까지 
 * 커널은 이 프로세스를 '잠자기(Sleep)' 상태로 둡니다.
 * Copy to User: 데이터가 들어오면 커널 메모리에 있는 데이터를 유저 메모리 주소(&ch)로 복사합니다.
 * Return: 다시 유저 모드로 돌아와 read() 다음 줄을 실행합니다.*/
