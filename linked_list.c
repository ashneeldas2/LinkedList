#include <stdlib.h>
#include <stdio.h>

struct node { int i; struct node *next; };
// function headers
void print_list(struct node *);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);

void print_list(struct node * n) {
    while (n) {
        printf("%d -> ", n -> i);
        n = n -> next;
    }
    printf("null\n");
}

struct node * insert_front(struct node * n, int val) {
    struct node * front = (struct node *) malloc(sizeof(struct node));
    front -> next = n;
    front -> i = val;
    return front;
}

struct node * free_list(struct node * n) {
    while(n){
        struct node * prev = n;
        n = n -> next;
        free(prev);
        prev = NULL;
    }
    return n;
}

int main() {
    struct node * test = (struct node *) malloc(sizeof(struct node));
    test -> i = 10;
    test = insert_front(test, 9);
    print_list(test);
    test = free_list(test);
    return 0;
}