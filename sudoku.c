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

    struct node *temp;
    // for(i=0; i<3; i++) {
    //     for(j=0; j<dimension; j++) {
    //         if(grid[i][j] == 0) {
    //             k = backtrack(grid, grid_size, i, j);
    //             print_stack();
    //             temp = pop();
    //             printf("x:%d r:%d c:%d\n", temp->x, temp->r, temp->c);
    //             grid[temp->r][temp->c] = temp->x;
    //         }
    //     }
    // }

    while(!finished(grid, dimension)) {
    // k=0;
    // while(k++ < 2) {
        find_next(grid, dimension, &i, &j);

        // if(backtrack(grid, grid_size, i, j)) { // MAPANLINLANG!! di ito backtracking
        k = populate(grid, grid_size, i, j);
        print_stack();
        temp = pop();
        grid[temp->r][temp->c] = temp->x;

        if(k == 0) backtrack(grid, temp, dimension, i, j);
        
        for(i=0; i<dimension; i++) {
            for(j=0; j<dimension; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        } 

        // } else {
        //     // do backtracking here
        //     // https://goo.gl/K8yCt5
        //     temp = pop();
        //     grid[temp->r][temp->c] = temp->x;  
        // }
    }
    


    // while(puzzle not finished) {
    //   find unassigned cell

    //   if(finished)
    //      return success

    //   perform backtracking
    //   if(backtracking is successful)
    //    return success
    // }

    teardown(grid, dimension);
    return 0;
}
