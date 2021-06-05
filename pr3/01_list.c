#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *next;
}tnode;

typedef struct list {
    struct node *l_begin;
}list;

void init(list *l)
{
    l -> l_begin = NULL;
}

void clean(list *l)
{
    if ((l -> l_begin == NULL))
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
    l->l_begin = NULL;
}
bool is_empty(list *l)
{
    if(l->l_begin == NULL)
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
    if (l -> l_begin != NULL)
    {
        tnode *current = l -> l_begin;
        while(current -> next != NULL)
        {
            current = current -> next;
        }
        tnode *temp = malloc(sizeof(tnode));
        current -> next = temp;
        temp -> next = NULL;
        temp -> value = val;
    }
    else
    {
        tnode *current = malloc(sizeof(tnode));
        current -> value = val;
        current -> next = NULL;
        l -> l_begin = current;
    }
    return 0;
}

int push_front(list *l, int val)
{
    tnode *current = malloc(sizeof(tnode));
    current -> value = val;
    current -> next = l -> l_begin;
    l -> l_begin = current;
    return 0;
}

int insert_after(tnode *n, int val)
{
    tnode *current = malloc(sizeof(tnode));
    current -> value = val;
    current -> next = n -> next;
    n -> next = current;
    return 0;
}

int remove_node(list *l, int val)
{
    tnode *current = l -> l_begin;
    tnode *prev = NULL;
    if(l -> l_begin == NULL)
    {
        return 1;
    }
    while(current -> value != val)
    {
        if(current -> next == NULL)
        {
            return 1;
        }
        else
        {
            prev = current;
            current = current -> next;
        }
    }
    if(current == l -> l_begin)
    {
        l -> l_begin = l -> l_begin -> next;
    }
    else
    {
        prev -> next = current -> next;
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
    tnode * a = find(l, x);
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
    print(l);
    (void)scanf("%d", &x);
    push_front(l, x);
    print(l);
    (void)scanf("%d %d", &y, &x);
    tnode *cur = find_index(l, y);
    insert_after(cur, x);
    print(l);
    (void) scanf("%d", &x);
    remove_node(l, x);
    print(l);
    clean(l);
    l -> l_begin = NULL;
    return 0;
}



