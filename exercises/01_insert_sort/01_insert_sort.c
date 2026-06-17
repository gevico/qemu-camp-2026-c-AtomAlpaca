#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int score;
} Student;

void move(Student students[], int l, int r) {
  for (int i = r; i >= l; --i) {
    students[i + 1] = students[i];
  }
  return ;
}

void insertion_sort(Student students[], int n) {
  for (int i = 2; i <= n; ++i) {
    Student tmp = students[i];
    for (int j = 1; j < i; ++j) {
      if (tmp.score > students[j].score) {
	move(students, j, i - 1);
	students[j] = tmp;
      }
    }
  }
}

int main(void) {
    FILE *file;
    Student students[50];
    int n = 0;
    
    // 打开文件（从命令行参数获取文件名）
    file = fopen("01_students.txt", "r");
    if (!file) {
        printf("错误：无法打开文件 01_students.txt\n");
        return 1;
    }
    
    // 从文件读取学生信息
    while (n < 50 && fscanf(file, "%s %d", students[n].name, &students[n].score) == 2) {
        n++;
    }
    fclose(file);
    
    if (n == 0) {
        printf("文件中没有学生信息\n");
        return 1;
    }
    
    insertion_sort(students, n);
    
    printf("\n按成绩从高到低排序后的学生信息:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }
    
    return 0;
}

