#include <stdio.h>
#include <string.h>

typedef struct {                
    int num;                    
    char name[20];              
    int clang, python, java;    
    int tot;                    
    double avg;                 
    char grade;                 
} Student;

void inputData(Student* pary);
void printData(Student* pary);
void calcData(Student* pary);
void sortData(Student* pary);

int main() {
    Student ary[5]; 
    inputData(ary);
    
    printf("\n정렬 전 데이터 ... \n");
    calcData(ary); // Calculate before printing
    printData(ary);
    
    sortData(ary);
    
    printf("\n정렬 후 데이터 ... \n");
    printData(ary);
    
    return 0;
}

void inputData(Student* pary) {
    int i;
    for(i = 0; i < 5; i++) {
        printf("%d번째 학생 번호, 이름, C/파이썬/자바 성적 입력: ", i + 1);
        scanf("%d %s %d %d %d", &pary[i].num, pary[i].name, &pary[i].clang, &pary[i].python, &pary[i].java);
    }
}

void printData(Student* pary) {
    int i;
    printf("\n번호  이름   C언어     파이썬    자바    총점    평균    학점\n");
    for(i = 0; i < 5; i++) {
        printf("%5d %7s %5d %5d %5d %5d %5.1lf %5c\n", 
               pary[i].num, pary[i].name, pary[i].clang, 
               pary[i].python, pary[i].java, pary[i].tot, 
               pary[i].avg, pary[i].grade);
    }
}

void calcData(Student* pary) {
    int i;
    for(i = 0; i < 5; i++) {
        pary[i].tot = pary[i].clang + pary[i].python + pary[i].java;
        pary[i].avg = pary[i].tot / 3.0;
        if(pary[i].avg >= 90) pary[i].grade = 'A';
        else if(pary[i].avg >= 80) pary[i].grade = 'B';
        else if(pary[i].avg >= 70) pary[i].grade = 'C';
        else pary[i].grade = 'F';
    }
}

// Corrected Selection Sort Function
void sortData(Student* pary) {
    int i, j, maxIdx;
    Student tmp;
    for(i = 0; i < 4; i++) {
        maxIdx = i;
        for(j = i + 1; j < 5; j++) {
            if(pary[j].tot > pary[maxIdx].tot) {
                maxIdx = j;
            }
        }
        // Swap entire structure
        tmp = pary[i];
        pary[i] = pary[maxIdx];
        pary[maxIdx] = tmp;
    }
}
