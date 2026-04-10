/* leetcode 200 - number of islands
 * Apr 7, 2026
 */


/* DFS */
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(char **grid, int size, int *col_size, int row, int col)
{
        if (row < 0 || row >= size || col < 0 || col >= col_size[row])
                return;

        if (grid[row][col] == '0')
                return;

        grid[row][col] = '0';

        for (int i = 0; i < 4; ++i) {
                int new_row = row + dirs[i][0];
                int new_col = col + dirs[i][1];
                dfs(grid, size, col_size, new_row, new_col);
        }
}

int numIslands_dfs(char **grid, int size, int *col_size)
{
        int count = 0;

        for (int i = 0; i < size; ++i) {
                for (int j = 0; j < col_size[i]; ++j) {
                        if (grid[i][j] == '1') {
                                ++count;
                                dfs(grid, size, col_size, i, j);
                        }
                }
        }

        return count;
}

/* BFS */
#include <stdlib.h>

typedef struct {
        int x;
        int y;
} point;

#define numIslands_bfs numIslands
int numIslands_bfs(char **grid, int size, int *col_size)
{
       int cnt = 0;
       int rows = size;
       int cols = col_size[0];

       int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

       point *queue = malloc(sizeof(point) * rows * cols);

       for (int i = 0; i < rows; ++i) {
               for (int j = 0; j < cols; ++j) {
                       if (grid[i][j] == '1') {
                               ++cnt;

                               int front = 0;
                               int rear = 0;

                               queue[rear].x = i;
                               queue[rear].y = j;
                               ++rear;
                               grid[i][j] = '0';

                               while (front < rear) {
                                       point curr = queue[front];
                                       ++front;

                                       for (int d = 0; d < 4; ++d) {
                                               int nx = curr.x + dirs[d][0];
                                               int ny = curr.y + dirs[d][1];

                                               if (nx >= 0 && nx < rows && ny >= 0 &&
                                                       ny < cols && grid[nx][ny] == '1') {
                                                               queue[rear].x = nx;
                                                               queue[rear].y = ny;
                                                               ++rear;
                                                               grid[nx][ny] = '0';
                                               }
                                       }
                               }
                       }

               }
       }

       free(queue);
       return cnt;
}
