#include "lib/sudoku.h"

int main() {
    int  i, j, k, count, grid_size;
    int  **grid;
    FILE *fp;

    fp = fopen("bin/data.in", "r");
    fscanf(fp, "%d", &count);

    for(i=0; i<count; i++) {
        fscanf(fp, "%d", &grid_size);
        grid_size *= grid_size;
        grid = init(grid_size);

        for(j=0; j<grid_size; j++) {
            for(k=0; k<grid_size; k++)
                fscanf(fp, "%d", &grid[j][k]);
        }
    }

    return 0;
}
