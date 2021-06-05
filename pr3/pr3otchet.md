# **Отчёт по третьей практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.


### Задания на практическую работу:

Реализовать программу, которая:
1. считывает количество элементов n, 0 < n <= 2147483647;
2. создает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. выводит содержимое списка, используя функцию print;
4. считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0", если нет (выводить через пробел, например "1 0 1");
5. считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. выводит содержимое списка, используя функцию print;
7. считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. выводит содержимое списка, используя функцию print;
9. считывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. выводит содержимое списка, используя функцию print;
11. считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
12. выводит содержимое списка, используя функцию print;
13. очищает список.



### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было настроить pipeline в файле .gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-75.userapi.com/impg/OulRbTclOnBRhlboC6pUK8qHqDMYHVH2y_bpUw/tTIC8Cbjy9M.jpg?size=116x108&quality=96&sign=3bb6f876fa3ef4df8842c81c9f27c8ff&type=album)
>Рисунок 1 - Добавление третьей работы

![pipeline](https://sun9-15.userapi.com/impg/cwbDAX2AHdl16rZInug58skX5poCYUgis2bo8w/ewUwhPCx5rY.jpg?size=312x477&quality=96&sign=689682f78a9b7a0ead87f3cb5c955bf5&type=album)
>Рисунок 2 - Добавление тестов
---

#### __3 Программа:__

В первую очередь необходимо было определить структуры, необходимые для решения данной задачи.

```c
typedef struct node{
    int value;
    struct node *next;
}tnode;

typedef struct list {
    struct node *l_begin;
}list;
```

Ниже приведены все функции, реализованные в программе.

__Инициализация пустого списка:__
```c
void init(list *l)
{
    l -> l_begin = NULL;
}
```

__Удаление всех элементов из списка:__
```c
void clean(list *l)
{
    if ((l -> l_begin == NULL))
    {
        return;
    }
    tnode *current = l -> l_begin;
    tnode *temp;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    l->l_begin = NULL;
}
```
__Проверка на пустоту списка:__
```c
bool is_empty(list *l)
{
    if(l->l_begin == NULL)
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
```

__Вставка значения в начало списка, вернуть 0 если успешно:__
```c
int push_front(list *l, int val)
{
    tnode *current = malloc(sizeof(tnode));
    current -> value = val;
    current -> next = l -> l_begin;
    l -> l_begin = current;
    return 0;
}
```

__Вставка значения после указанного узла, вернуть 0 если успешно:__
```c
int insert_after(tnode *n, int val)
{
    tnode * current = malloc(sizeof(tnode));
    current -> value = val;
    current -> next = n -> next;
    n -> next = current;
    return 0;
}
```

__Удаление первого элемента из списка с указанным значением, вернуть 0 если успешно:__
```c
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
```

На рис. 3 представлен результат тестирования pipeline.

![Результат pipeline](https://sun9-49.userapi.com/impg/wrKf1P1gtcKY1rzagREV5kBLegfGv9xYBTTuTQ/A_NBtCtlV9c.jpg?size=763x444&quality=96&sign=ea1390e05c0d8595865dcf011f325356&type=album)
>Рисунок 3 - Результат теста pipeline

---


### __Заключение__
В ходе данной практической работы была решена задача по теме "Односвязные списки". Реализованы все заданные структуры и функции. Написанная программа успешно прошла все тесты и проверки.
