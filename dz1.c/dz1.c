#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 32

struct List{
  int data;
  struct List *next;
};

void list_add(struct List **L, int data){
    struct List *L2 = (struct List*) malloc(sizeof(struct List));
    
    L2->data = data;
    L2->next = *L;
    *L = L2;
}

struct List *list_delete(struct List *L, int n){
    if(L == NULL){
        return NULL;
    }
    if(n==1){
        if(L->next == NULL){
            free(L);
            return NULL;
        } else {
            struct List *p = L->next;
            free(L);
            return p;
        }
    } else {
        n--;
        L->next = list_delete(L->next, n);
    }
    return L;
}

void list_print(struct List *L){
    if(L == NULL){
        printf("There is no info!\n");
    }
    while(L != NULL){
        printf(" %d\n", L->data);
        L = L->next;
    }
    
    
}

int main(){
    struct List *L = NULL;
    int i=0;
    while(1){
        printf("1 - add\n");
        printf("2 - delete\n");
        printf("3 - print list\n");

        scanf("%d", &i);
        
        if(i == 1){
            printf("enter data: ");
            int data;
            scanf("%d", &data);
            list_add(&L, data);
        } else if(i == 2){
            printf("enter num element to delete: ");
            int n;
            scanf("%d", &n);
            L = list_delete(L, n);
        } else if (i == 3){
            list_print(L);
        }
    }
    
    return 0;
}
