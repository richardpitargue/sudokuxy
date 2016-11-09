#include "lib/sudoku.h"

int main() {
    int  i, j, k, count, grid_size, dimension;
    int  **grid;
    FILE *fp;

    fp = fopen("bin/data.in", "r");
    fscanf(fp, "%d", &count);

    for(i=0; i<count; i++) {
        fscanf(fp, "%d", &grid_size);
        dimension = grid_size*grid_size;
        grid = init(dimension);

        for(j=0; j<dimension; j++) {
            for(k=0; k<dimension; k++)
                fscanf(fp, "%d", &grid[j][k]);
        }
    }

    printf("%d\n", finished(grid, dimension));
    i = validate(grid, grid_size);

    teardown(grid, dimension);
    return 0;
}
