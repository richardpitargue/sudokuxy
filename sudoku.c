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

    struct node *temp = NULL;
    struct node *p, *p2;
    while(!finished(grid, dimension)) {
        find_next(grid, dimension, &i, &j);

        k = populate(grid, grid_size, i, j);
        p = pop();
        
        if(k == 0) {
            p2 = temp;
            while(p2->r >= p->r && p2->c >= p->c) {
                temp = temp->next;
                p2->next = NULL;

                grid[p2->r][p2->c] = 0;
                p2 = temp;
            }
        }

        if(temp == NULL) {
            temp = p;
            temp->next = NULL;
        } else {
            p->next = temp;
            temp = p;
        }
        grid[p->r][p->c] = p->x;

    }

    teardown(grid, dimension);
    return 0;
}
