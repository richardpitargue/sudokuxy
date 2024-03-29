#include <stdio.h>
#include <stdlib.h>

struct node {
    int x;
    int r;
    int c;
    struct node * next;
};

/***        Global Variable        ***/
struct node *head = NULL;

void push(int x, int r, int c) {
    struct node *p;

    p = malloc(sizeof(struct node));
    p->x = x;
    p->r = r;
    p->c = c;
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

void print_stack(struct node *temp) {
    struct node *p;
    p = temp;
    while(p != NULL) {
        printf("%d.%d.%d -> ", p->x, p->r, p->c);
        p = p->next;
    }
    printf("EOS\n");
}
