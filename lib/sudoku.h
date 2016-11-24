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

int duplicate(int *buffer, int *x) {
    if(*x >= 0) {
        buffer[*x] += 1;
        if(buffer[*x] != 1) {
            free(buffer);
            return 1;
        }
    }

    return 0;
}

int validateX(int **grid, int grid_size) {
    int *buffer;
    int dimension;
    int i, j, k, l, x;

    dimension = grid_size*grid_size;
    buffer = (int *)malloc(sizeof(int)*dimension);
    for(i=0; i<dimension; i++) buffer[i] = 0;

    /***        Check X        ***/
    for(i = 0; i < dimension; i++) {
        x = grid[i][i]-1;
        if(duplicate(buffer, &x)) {
            return 0;
        }
    }
    for(x=0; x<dimension; x++) buffer[x] = 0;
 
    for(i = 0; i < dimension; i++) {
        x = grid[i][(dimension-1)-i]-1;
        if(duplicate(buffer, &x)) {
            return 0;
        }
    }
    for(x=0; x<dimension; x++) buffer[x] = 0;

    /***        Check Rows        ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[i][j]-1;
            if(duplicate(buffer, &x))
                return 0;
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
    }

    /***       Check Columns       ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[j][i]-1;
            if(duplicate(buffer, &x))
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
                    if(duplicate(buffer, &x))
                        return 0;
                }
            }
            for(x=0; x<dimension; x++) buffer[x] = 0;
        }
    }

    free(buffer);
    return 1;
}

int validateY(int **grid, int grid_size) {
    int *buffer;
    int dimension;
    int i, j, k, l, x;

    dimension = grid_size*grid_size;
    buffer = (int *)malloc(sizeof(int)*dimension);
    for(i=0; i<dimension; i++) buffer[i] = 0;

    /***        Check Y        ***/
    if(dimension % 2 != 0){
      // left wing
      for(i=0; i<(dimension/2); i++){
        for(j=0; j<dimension; j++){
          if((i == j && (j < (dimension/2))) || ((i == (dimension/2)) && (j >= (dimension/2)))){
            x = grid[i][j]-1;
            if(duplicate(buffer, &x))
                return 0;
          }
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
      }

      // right wing
      for(i=((dimension/2)+1); i<dimension; i++){
        for(j=0; j<dimension; j++){
          if((j == (dimension-i-1) && (j < (dimension/2))) || ((i == (dimension/2)) && (j >= (dimension/2)))){
            x = grid[i][j]-1;
            if(duplicate(buffer, &x))
                return 0;
          }
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
      }
    } else {
        return 0;
    }

    /***        Check Rows        ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[i][j]-1;
            if(duplicate(buffer, &x))
                return 0;
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
    }

    /***       Check Columns       ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[j][i]-1;
            if(duplicate(buffer, &x))
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
                    if(duplicate(buffer, &x))
                        return 0;
                }
            }
            for(x=0; x<dimension; x++) buffer[x] = 0;
        }
    }

    free(buffer);
    return 1;
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
            if(duplicate(buffer, &x))
                return 0;
        }
        for(x=0; x<dimension; x++) buffer[x] = 0;
    }

    /***       Check Columns       ***/
    for(i=0; i<dimension; i++) {
        for(j=0; j<dimension; j++) {
            x = grid[j][i]-1;
            if(duplicate(buffer, &x))
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
                    if(duplicate(buffer, &x))
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

int populate(int type, int **grid, int grid_size, int r, int c) {
    int i, dimension, flag;

    dimension = grid_size*grid_size;
    flag = 0;

    for(i=dimension; i>0; i--) {
        grid[r][c] = i;
        switch(type) {
            case 0:
                if(validate(grid, grid_size)) {
                    push(i, r, c);
                    flag = 1;
                } else grid[r][c] = 0;
                break;
            case 1:
                if(validateX(grid, grid_size)) {
                    push(i, r, c);
                    flag = 1;
                } else grid[r][c] = 0;
                break;
            case 2:
                if(validateY(grid, grid_size)) {
                    push(i, r, c);
                    flag = 1;
                } else grid[r][c] = 0;
                break;
        }
    }

    return flag;
}

void teardown(int **grid, int dimension) {
    int i;

    for(i=0; i<dimension; i++)
        free(grid[i]);
    free(grid);

    return;
}
