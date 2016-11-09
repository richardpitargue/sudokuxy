#include "stack.h"

int ** init(int dimension) {
    int **grid;
    int i;

    grid = (int **)malloc(sizeof(int *)*dimension);
    for(i=0; i<dimension; i++) {
        grid[i] = (int *)malloc(sizeof(int)*dimension);
    }

    return grid;
}
