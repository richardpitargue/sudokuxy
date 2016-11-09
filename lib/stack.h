#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    int row;
    int col;
    struct node * next;
};

/***        Global Variable        ***/
struct node *head = NULL;

void push(int x, int r, int c) {
    struct node *p;

    p = malloc(sizeof(struct node));
    p->x = x;
    p->next = head;
    head = p;

    return;
}

struct node * pop() {
    struct node *p;
    if(head != NULL) {
        p = head;
        head = head->next;
    }

    return p;
}

struct node * peak() {
    struct node *p;
    if(head != NULL) p = head;

    return p;
}

void print_stack() {
    struct node *p;
    p = head;
    while(p != NULL) {
        printf("%d -> ", p->x);
        p = p->next;
    }
    printf("EOS\n");
}
