#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
}tnode;
typedef struct list {
    struct node *l_begin;
    struct node *l_end;
}list;
void init(list *l)
{
    l -> l_begin = NULL;
    l -> l_end = NULL;
}
void clean(list *l)
{
    if (l -> l_begin == NULL)
    {
        return;
    }
    tnode *current = l->l_begin;
    tnode *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    l -> l_begin = NULL;
    l -> l_end = NULL;
}
bool is_empty(list *l)
{
    if(l -> l_begin == NULL)
    {
        return true;
    }
    return false;
}
tnode *find(list *l, int val)
{
    tnode *current = l -> l_begin;
    if(l -> l_begin == NULL)
    {
        return NULL;
    }
    while(current -> value != val)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
    }
    return current;
}
int push_back(list *l, int val)
{
    tnode *lastnode = l -> l_end;
    tnode *current = malloc(sizeof(tnode));
    if (l -> l_end != NULL)
    {
        lastnode -> next = current;
        current -> value = val;
        current -> next = NULL;
        current -> prev = l -> l_end;
        l -> l_end = current;
    }
    else
    {
        current -> value = val;
        current -> next = NULL;
        current -> prev = NULL;
        l -> l_end = current;
        l -> l_begin = current;
    }
    return 0;
}
int push_front(list *l, int val)
{
    tnode *firstnode = l -> l_begin;
    tnode *current = malloc(sizeof(tnode));
    firstnode -> prev = current;
    current -> value = val;
    current -> next = l -> l_begin;
    current -> prev = NULL;
    l -> l_begin = current;
    return 0;
}
int insert_after(list *l, tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    if (n -> next == NULL) //Если n - последний узел
    {
        current -> value = val;
        current -> next = NULL;
        n -> next = current;
        current -> prev = l -> l_end;
        l -> l_end = current;        
    }
    else //Если n - не последний узел
    {
        tnode *nextnode = n -> next;
        current -> value = val;
        current -> next = nextnode;
        n -> next = current;
        current -> prev = n;
        nextnode -> prev = current;
    }
    return 0;
}
int insert_before(list *l, tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    if (n -> prev == NULL) //Если n - первый узел
    {
        current -> value = val;
        current -> next = n;
        n -> prev = current;
        current -> prev = NULL;
        l -> l_begin = current;
    }
    else //Если n - не первый узел
    {
        tnode *prevnode = n -> prev;
        current -> value = val;
        current -> prev = prevnode;
        n -> prev = current;
        current -> next = n;
        prevnode -> next = current;
    }
    return 0;
}
int remove_first(list *l, int val)
{
    tnode *current = l -> l_begin;
    if(l -> l_begin == NULL)
    {
        return 1;
    }
    while((current -> value != val) && (current -> next != NULL))
    {
        current = current -> next;
    }
    if(current -> value != val) return 0;
    if((l -> l_begin == current) && (l -> l_end == current)) //Если current - единственный узел
    {
        l -> l_begin = NULL;
        l -> l_end = NULL;
    }
    else if(l -> l_begin == current) //Если current - первый узел
    {
        current -> next -> prev = NULL;
        l -> l_begin = l -> l_begin -> next;
    }
    else if(l -> l_end == current) //Если  current - последний узел
    {
        current -> prev -> next = NULL;
        l -> l_end = l -> l_end -> prev;
    }
    else //Если в где-то середине
    {
        current -> next -> prev = current -> prev;
        current -> prev -> next = current -> next;
    }
    free(current);
    return 0;
}
int remove_last(list *l, int val)
{
    tnode *current = l -> l_end;
    if(l -> l_begin == NULL)
    {
        return 1;
    }
    while((current -> value != val) && (current -> prev != NULL))
    {
        current = current -> prev;
    }
    if(current -> value != val) return 0;
    if((l -> l_begin == current) && (l -> l_end == current)) //Если current - единственный узел
    {
        l -> l_begin = NULL;
        l -> l_end = NULL;
    }
    else if(l -> l_begin == current) //Если current - первый узел
    {
        current -> next -> prev = NULL;
        l -> l_begin = l -> l_begin -> next;
    }
    else if(l -> l_end == current) //Если  current - последний узел
    {
        current -> prev -> next = NULL;
        l -> l_end = l -> l_end -> prev;
    }
    else //Если в где-то середине
    {
        current -> next -> prev = current -> prev;
        current -> prev -> next = current -> next;
    }
    free(current);
    return 0;
}
void print(list *l)
{
    tnode *current = l -> l_begin;
    if (current == NULL)
    {
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current-> value);
        current = current -> next;
    }
    printf("\n");
}
void print_invers(list *l)
{
    tnode *current = l -> l_end;
    if (current == NULL)
    {
        return;
    }
    while(current != NULL)
    {
        printf("%d ", current-> value);
        current = current -> prev;
    }
    printf("\n");
}
tnode *find_index(list *l, int val)
{
    if(l -> l_begin == NULL)
    {
        return NULL;
    }
    tnode *current = l -> l_begin;
    int i = 1;
    while(i != val)
    {
        current = current -> next;
        if(current == NULL)
        {
            return NULL;
        }
        i++;
    }
    return current;
}
int main() {
    int i, n, x, y, z;
    list *l;
    l = malloc(sizeof(list));
    init(l);
    (void) scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        (void) scanf("%d", &x);
        push_back(l, x);
    }
    print(l);
    (void) scanf("%d %d %d", &x, &y, &z);
    tnode *a = find(l, x);
    if(a == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    tnode * b = find(l, y);
    if(b == NULL)
    {
        printf("0 ");
    }
    else
    {
        printf("1 ");
    }
    tnode * c = find(l, z);
    if(c == NULL)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
    (void)scanf("%d", &x);
    push_back(l, x);
    print_invers(l);
    (void)scanf("%d", &x);
    push_front(l, x);
    print(l);
    (void)scanf("%d %d", &y, &x);
    tnode *cur1 = find_index(l, y);
    insert_after(l, cur1, x);
    print_invers(l);
    (void)scanf("%d %d", &y, &x);
    tnode *cur2 = find_index(l, y);
    insert_before(l, cur2, x);
    print(l);
    (void) scanf("%d", &x);
    remove_first(l, x);
    print_invers(l);
    (void) scanf("%d", &x);
    remove_last(l, x);
    print(l);
    clean(l);
    l -> l_begin = NULL;
    return 0;
}
