#include <stdio.h>
#include <stdbool.h>

#define MAX_PEOPLE 50

typedef struct {
    int id;
} People;

typedef struct {
    People data[MAX_PEOPLE];
    int head;
    int tail;
    int count;
} Queue;

int main() {
    Queue q;
    int total_people=50;
    int report_interval=5;

    q.head = 0; q.tail = 49; q.count = 50;
    for (int i = 0; i < 50; ++i) {
      q.data[i].id = i + 1;
    }
    for (int i = 1; i <= 49; ++i) {
      for (int j = 1; j <= 4; ++j) {
	q.tail = (q.tail + 1) % 50;
	q.data[q.tail] = q.data[q.head];
	q.head = (q.head + 1) % 50;
      }
      printf("淘汰: %d\n", q.data[q.head].id);
      q.head = (q.head + 1) % 50;
    }
    
    printf("最后剩下的人是: %d\n", q.data[q.head].id);

    return 0;
}
