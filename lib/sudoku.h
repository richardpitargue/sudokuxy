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

int finished(int **grid, int dimension) {
    int i, j;

    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            if(grid[i][j] == 0) return 0;
        }
    }

    return 1;
}

int duplicate(char *err, int *buffer, int *x, int *r, int *c) {
    int i;

    if(*x >= 0) {
        buffer[*x] += 1;
        if(buffer[*x] != 1) {
            // printf("%s ERROR: Invalid input at r:%d c:%d\n", err, *r, *c);
            free(buffer);
            return 1;
        }
    }

    return 0;
}

int validate(int **grid, int grid_size) {
    int *buffer;
    int dimension;
    int i, j, k, l, x;

    dimension = grid_size*grid_size;
    buffer = (int *)malloc(sizeof(int)*dimension);
    for(i=0; i<dimension; i++) buffer[i] = 0;

    /***        Check Rows        ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[i][j]-1;
            if(duplicate("ROW", buffer, &x, &i, &j))
                return 0;
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
    }

    /***       Check Columns       ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[j][i]-1;
            if(duplicate("COL", buffer, &x, &j, &i))
                return 0;
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
    }

    /***       Check Grids       ***/
    for(i=0; i<dimension; i+=grid_size) {
        for(j=0; j<dimension; j+=grid_size) {
            for(k=i; k<(i+grid_size); k++) {
                for(l=j; l<(j+grid_size); l++) {
                    x = grid[k][l]-1;
                    if(duplicate("GRID", buffer, &x, &k, &l))
                        return 0;
                }
            }
            for(x=0; x<dimension; x++) buffer[x] = 0;
        }
    }

    free(buffer);
    return 1;
}

void find_next(int **grid, int dimension, int *r, int *c) {
    for(*r = 0; *r < dimension; (*r)++) {
        for(*c = 0; *c < dimension; (*c)++) {
            if(grid[*r][*c] == 0) return;
        }
    }
}

int populate(int **grid, int grid_size, int r, int c) {
    int i, dimension, flag;

    dimension = grid_size*grid_size;
    flag = 0;

    for(i=dimension; i>0; i--) {
        grid[r][c] = i;
        if(validate(grid, grid_size)) {
            push(i, r, c);
            flag = 1;
        } else grid[r][c] = 0;
    }

    return flag;
}

void backtrack() {


}

void teardown(int **grid, int dimension) {
    int i;

    for(i=0; i<dimension; i++)
        free(grid[i]);
    free(grid);

    return;
}
