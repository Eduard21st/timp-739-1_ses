# **Отчёт по четвертой практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.


### Задания на практическую работу:

Реализовать программу, которая:
1. считывает количество элементов n, 0 < n <= 2147483647;
2. создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. выводит содержимое списка, используя функцию print;
4. считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0" если нет (выводить через пробел, например "1 0 1");
5. считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. выводит содержимое списка, используя функцию print_invers;
7. считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. выводит содержимое списка, используя функцию print;
9. считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. выводит содержимое списка, используя функцию print_invers;
11. считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;
12. выводит содержимое списка, используя функцию print;
13. считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
14. выводит содержимое списка, используя функцию print_invers;
15. считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;
16. выводит содержимое списка, используя функцию print;
17. очищает список.


### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было настроить pipeline в файле .gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-28.userapi.com/impg/5nyaHKMCwoq1GLE7bw3Mxfr130_JKQNOr6Uzbg/bY2nt8vmk4U.jpg?size=439x159&quality=96&sign=2ff937e636b06da570ab3e2b530c3552&type=album)
>Рисунок 1 - Добавление третьей работы

![pipeline](https://sun9-55.userapi.com/impg/IZ8H--Ukm9GmBJX_7oFCJNLVAoLIjisiGYmwPg/ZdrPoFCUZL4.jpg?size=312x363&quality=96&sign=9976c15a1a75e57649bfd0018c879e8a&type=album)
>Рисунок 2 - Добавление тестов
---

#### __3 Программа:__

В первую очередь необходимо было определить структуры, необходимые для решения данной задачи.

```c
typedef struct node{
    int value;
    struct node *next;
    struct node *prev;
}tnode;
typedef struct list {
    struct node *l_begin;
    struct node *l_end;
}list;
```

Ниже приведены все функции, реализованные в программе.

__Инициализация пустого списка:__
```c
void init(list *l)
{
    l -> l_begin = NULL;
    l -> l_end = NULL;
}
```

__Удаление всех элементов из списка:__
```c
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
```
__Проверка на пустоту списка:__
```c
bool is_empty(list *l)
{
    if(l -> l_begin == NULL)
    {
        return true;
    }
    return false;
}
```

__Поиск элемента по значению, вернуть NULL если элемент не найден:__
```c
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
```

__Вставка значения в конец списка, вернуть 0 если успешно:__
```c
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
```
__Вставка значения в начало списка, вернуть 0 если успешно:__

```c
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

```

__Вставка значения после указанного узла, вернуть 0 если успешно:__
```c
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
```

__Вставка значения перед указанным узлом, вернуть 0 если успешно:__
```c
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
```

__Удаление первого элемента из списка с указанным значением, вернуть 0 если успешно:__
```c
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
```

__Удаление последнего элемента из списка с указанным значением, вернуть 0 если успешно:__
```c
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
```

__Вывод всех значений списка в прямом порядке через пробел, после окончания вывода перейти на новую строку:__
```c
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
```
__Вывод всех значений списка в обратном порядке через пробел, после окончания вывода перейти на новую строку:__
```c
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
```

__Метод main:__
```c
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
```

На рис. 3 представлен результат тестирования pipeline.

![Результат pipeline](https://sun9-70.userapi.com/impg/iWnlWQOAruAWoIFQbOdRGKvHlXuqb18t8MU8Nw/YfrCp-l49lE.jpg?size=219x200&quality=96&sign=8fa4dce8d89462ffd13c9d1ac8074dad&type=album)
>Рисунок 3 - Результат теста pipeline

---


### __Заключение__
В ходе данной практической работы была решена задача по теме "Двусвязные списки". Реализованы все заданные структуры и функции. Написанная программа успешно прошла все тесты и проверки.
