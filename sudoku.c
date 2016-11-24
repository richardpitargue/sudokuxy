#include "lib/sudoku.h"

int main() {
    int  i, j, k, count, counter, grid_size, dimension, x;
    int  **grid;
    FILE *fp;

    fp = fopen("bin/input2.txt", "r");
    fscanf(fp, "%d", &count);


    for(counter=0; counter<count; counter++) {
        fscanf(fp, "%d", &grid_size);
        dimension = grid_size*grid_size;
        grid = init(dimension);

        for(j=0; j<dimension; j++) {
            for(k=0; k<dimension; k++)
                fscanf(fp, "%d", &grid[j][k]);
        }

        struct node *temp = NULL;
        struct node *p, *p2;
        x = 0;
        do {
            if(finished(grid, dimension)) {
                x++;
                k = 0;
            } else {
                find_next(grid, dimension, &i, &j);
                k = populate(3, grid, grid_size, i, j);
            }
            if(head == NULL) break;
            p = pop();

            if(k == 0) {
                p2 = temp;
                while(temp != NULL && (dimension*p2->r)+p2->c >= (dimension*p->r)+p->c) {
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

            // for(i=0; i<dimension; i++){
            //   for(j=0; j<dimension; j++){
            //     printf("%d ", grid[i][j]);
            //   }
            //   printf("\n");
            // }
            // printf("--------------------------------\n");
        }while(1);
        printf("Number of solutions: %d\n", x);
    }

    fclose(fp);
    teardown(grid, dimension);
    return 0;
}
