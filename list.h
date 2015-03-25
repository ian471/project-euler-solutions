#include <stdlib.h>

struct list_struct {
    int val;
    struct list_struct* next;
};
typedef struct list_struct list;

int list_length(list * l) {
    int len = 0;
    while(l) {
        ++len;
        l = l->next;
    }
    return len;
}

list* list_create(int val) {
    list * r = (list*) malloc(sizeof(list));
    r->val = val;
    r->next = NULL;
    return r;
}

list* list_create_empty() {
    return NULL;
}

void list_destroy(list * l) {
    if(!l) return;
    list *n = l->next;
    free(l);
    list_destroy(n);
}

void list_push(list ** l, int val) {
    list * new = list_create(val);
    new->next = *l;
    *l = new;
}

int list_pop(list ** l) {
    int ret = (*l)->val;
    list * destroy = *l;
    *l = (*l)->next;
    destroy->next = NULL;
    list_destroy(destroy);
    return ret;
}

list * list_next(list * l) {
    return l->next;
}
