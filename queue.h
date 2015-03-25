#include <stdlib.h>

struct queue_item {
    int val;
    struct queue_item* next;
};
typedef struct {
    struct queue_item *head, *tail;
    int length;
} queue;

queue *queue_create() {
    queue *q = malloc(sizeof(queue));
    q->head = q->tail = NULL;
    q->length = 0;
    return q;
}

#define queue_length(q) (q->length)
/*
int queue_length(queue *q) {
    return q->length;
}*/

void queue_enqueue(queue *q, int val) {
    struct queue_item *new = malloc(sizeof(struct queue_item));
    new->val = val;
    new->next = NULL;
    if(q->tail) {
        q->tail->next = new;
    } else {
        q->head = new;
    }
    q->tail = new;
    ++ q->length;
}

int queue_dequeue(queue *q) {
    if(!q->head) return 0;
    int ret = q->head->val;
    struct queue_item *freeme = q->head;
    if(q->tail == q->head) {
        q->tail = q->head = NULL;
        q->length = 0;
    } else {
        q->head = q->head->next;
        -- q->length;
    }
    free(freeme);
    return ret;
}

int queue_contains(queue *q, int val) {
    struct queue_item *i = q->head;
    while(i) {
        if(i->val == val) return 1;
        i = i->next;
    }
    return 0;
}
