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
int xs[MAX], ys[MAX], ansx[MAX], ansy[MAX];
bool b[MAX_ROW][MAX_COL] = {0};

int main(void)
{
  int top = 1, anstop = 0;
  xs[1] = ys[1] = 0;
  ansx[0] = ansy[0] = 10;
  while (1) {
    int x = xs[top];
    int y = ys[top];

    if (b[x][y]) { --top; continue; }
    b[x][y] = 1;
    
    ++anstop; ansx[anstop] = x; ansy[anstop] = y;
    if (x == 4 && y == 4) {
      for (int i = anstop; i >= 1; --i) {
	printf("(%d, %d)\n", ansx[i], ansy[i]);
      }
      return 0;
    }
    if (   (x == ansx[anstop - 1] - 1 || x + 1 > 4 || maze[x + 1][y] || b[x + 1][y])
	&& (y == ansy[anstop - 1] - 1 || y + 1 > 4 || maze[x][y + 1] || b[x][y + 1])
	&& (x == ansx[anstop - 1] + 1 || x - 1 < 0 || maze[x - 1][y] || b[x - 1][y])
	&& (y == ansy[anstop - 1] + 1 || x + 1 < 0 || maze[x][y - 1] || b[x][y - 1])) {
      --top; --anstop; continue;
    }

    if (x != ansx[anstop] - 1 && x + 1 <= 4 && !maze[x + 1][y] && !b[x + 1][y]) {
      ++top; xs[top] = x + 1; ys[top] = y;
    }
    if (y != ansy[anstop] - 1 && y + 1 <= 4 && !maze[x][y + 1] && !b[x][y + 1]) {
      ++top; xs[top] = x; ys[top] = y + 1;
    }
    if (x != ansx[anstop] + 1 && x - 1 >= 0 && !maze[x - 1][y] && !b[x - 1][y]) {
      ++top; xs[top] = x - 1; ys[top] = y;
    }
    if (y != ansy[anstop] + 1 && y - 1 >= 0 && !maze[x][y - 1] && !b[x][y - 1]) {
      ++top; xs[top] = x; ys[top] = y - 1;
    }
  }
	return 0;
}
