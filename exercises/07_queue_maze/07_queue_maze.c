#include <stdio.h>
#include <stdbool.h>

#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

#define MAX 100

int xs[MAX], ys[MAX], f[MAX];
bool b[MAX_ROW][MAX_COL];

int main(void)
{
  int l = 1, r = 1;
  int ap = 0;
  xs[1] = 0; ys[1] = 0; f[1] = 0;
  while (1) {
    int x = xs[l], y = ys[l];
    b[x][y] = 1;
    if (x == 4 && y == 4) {
      for (int i = l; i != 0; i = f[i]) {
	printf("(%d, %d)\n", xs[i], ys[i]);
      }
      break;
    }
    if (   (x - 1 < 0 || maze[x - 1][y] || b[x - 1][y])
	&& (y - 1 < 0 || maze[x][y - 1] || b[x][y - 1])
	&& (x + 1 > 4 || maze[x + 1][y] || b[x + 1][y])
	&& (y + 1 > 4 || maze[x][y + 1] || b[x][y + 1])) {
      ++l; continue;
    }
    if (x - 1 >= 0 && !maze[x - 1][y] && !b[x - 1][y]) {
      ++r; xs[r] = x - 1; ys[r] = y; f[r] = l;
    }
    if (y - 1 >= 0 && !maze[x][y - 1] && !b[x][y - 1]) {
      ++r; xs[r] = x; ys[r] = y - 1; f[r] = l;
    }
    if (x + 1 <= 4 && !maze[x + 1][y] && !b[x + 1][y]) {
      ++r; xs[r] = x + 1; ys[r] = y; f[r] = l;
    }
    if (y + 1 <= 4 && !maze[x][y + 1] && !b[x][y + 1]) {
      ++r; xs[r] = x; ys[r] = y + 1; f[r] = l;
    }
    ++l;
  }
  return 0;
}
