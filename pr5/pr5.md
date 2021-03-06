# **Отчёт по пятой практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.


### Задания на практическую работу:

Реализовать программу, которая:
1. создает пустое дерево, считывает 4 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
2. выводит дерево (используя функцию print_tree) и пустую строку;
3. считывает 3 элемента ai, |ai| <= 2147483647 и заносит их в дерево;
4. выводит дерево и пустую строку;
5. считывает m1, |m1| <= 2147483647 и ищет элемент с заданным значением в дереве;
выводит через пробел значение предка и потомков найденного элемента,
если нет значений предка или потомков вывести "_" вместо таких значений;
вывести "-", если элемент не найден; вывести пустую строку;
6. считывает m2, |m2| <= 2147483647 и ищет элемент с заданным значением в дереве;
выводит через пробел значение предка и потомков найденного элемента,
если нет значений предка или потомков вывести "_" вместо таких значений;
вывести "-", если элемент не найден; вывести пустую строку;
7. считывает m3, |m3| <= 2147483647 и удаляет из дерева элемент с заданным значением (если такой элемент есть);
8. выводит дерево и пустую строку;
9. выполняет левый поворот дерева относительно корня, пока это возможно;
10. выводит дерево и пустую строку;
11. выполняет правый поворот дерева относительно корня, пока это возможно;
12. выводит дерево и пустую строку;
13. выводит на экран количество элементов в дереве и пустую строку
14. очищает дерево
15. выводит дерево и пустую строку;


### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было настроить pipeline в файле .gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-23.userapi.com/impg/LBKGy8YMO4oIrHCVcZCXfO2gP3vMQB0PUU4jyw/7kobRA6zcmM.jpg?size=120x39&quality=96&sign=fc6378385bf57cae4bb861c003edadb4&type=album)
>Рисунок 1 - Добавление пятой работы

![pipeline](https://sun9-14.userapi.com/impg/pXqDB6rhOL_ODEtHMrH8o8nN3_NpBvtqR6LtZg/3FbQZ7fJvO0.jpg?size=470x226&quality=96&sign=a7bf5e8b8d3ba93afa5e4196a3fa3666&type=album)
>Рисунок 2 - Добавление тестов
---

#### __3 Программа:__

В первую очередь необходимо было определить структуры, необходимые для решения данной задачи.

```c
typedef struct node {
    int value;
    struct node *parent; //предок
    struct node *left;  //потомки
    struct node *right;
} node;
typedef struct tree {
    struct node *root;
    int count;
} tree;
```

Ниже приведены все функции, реализованные в программе.

__Инициализация пустого списка:__
```c
void init(list *l)
{
    void init(tree* t)
	{
    t -> root = NULL;
    t -> count = 0;
	}
}
```

__Удаление элементов из списка:__
```c
void clean2(node *n)
{

    if (n->right != NULL)
        clean2(n->right);
    if (n->left != NULL)
        clean2(n->left);
    free(n);
}
void clean(tree *t,node *n)
{
    if(t->root == NULL)
        return;
    clean2(n);
    free(t);
}
```

__Поиск элемента по значению, вернуть NULL если элемент не найден:__
```c
node *find(tree* t, int value)
{
    node * current;
    current = t->root;

    if (t->root == NULL)
    {
        return NULL;
    }
    while (current != NULL)
    {
        if (current->value == value)
        {
            return current;
        }
        else if (value > current->value)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    return NULL;
}
```

__Вставка значения в дерево:__
```c
// 0 - вставка выполнена успешно
// 1 - элемент существует
// 2 - не удалось выделить память для нового элемента
int insert(tree* t, int value)
{
    struct node *current,*last_n = NULL;

    node* check = find(t, value);
    if (check != NULL)
    {
        return 1;
    }
    current = t->root;

    while(current!=NULL) //поиск узла, где будет новое значение
    {
        last_n = current;
        if(value > current -> value)
            current = current->right;
        else
            current = current->left;
    }
    current = malloc(sizeof *current);
    if (current != NULL)
    {
        current->value= value;
        current->left = NULL;
        current->right = NULL;
        current->parent = last_n;
        if(last_n != NULL) //если предок не корень
        {
            if(current -> value < last_n -> value)
                last_n -> left = current;
            else
                last_n -> right = current;
        }
        if(t->count == 0) // если нет узлов
        {
            t -> root = current;
        }
        t->count++;
        return 0;
    }
    else  //не удалось выделить память для нового элемента
    {
        return 2;
    }
}
```

__Удаление первого элемента из дерева с указанным значением:__
```c
// 0 - удаление прошло успешно
// 1 - нет элемента с указанным значением
int remove_node(tree* t, int value)
{
    node *n = find(t,value);
    if(n == NULL)
        return 1;

    if(n->left == NULL && n->right == NULL) //без потомков
    {
        if(n == t->root)
        {
            t->root = NULL;
        }
        else if(n == n->parent->right)
            n->parent->right = NULL;
        else n->parent->left = NULL;
    }
    else if(n->left == NULL) //существует только правый потомок
    {
        if(n == t->root)
        {
            t->root = n->right;
            n->right->parent = NULL;
        }
        else
        {
            if(n == n->parent->right)
                n->parent->right = n->right;
            else n->parent->left = n->right;
            n->right->parent = n->parent;
        }
    }
    else if(n->right == NULL)  //существует только левый потомок
    {
        if (n == t->root)
        {
            t->root = n->left;
            n->left->parent = NULL;
        }
        else
        {
            if(n == n->parent->right)
                n->parent->right = n->left;
            else n->parent->left = n->left;
            n->left->parent = n->parent;
        }
    }
    else  //существует оба потомка
    {
        node *current = n->right;
        if(current->left == NULL)  //у правого поддерева нет левого поддерева
        {
            current->parent = n->parent;
            current->left = n->left;
            if(t->root == n)
                t->root = current;
            else
            {
                if(n->value > n->parent->value)
                    n->parent->right = current;
                else n->parent->left = current;
            }
        }
        else
        {
            while(current->left != NULL)
            {
                current = current -> left;
            }
            current->parent->left = NULL;
            if(t->root == n)
                t->root = current;
            else
            {
                if(n->value > n->parent->value)
                    n->parent->right = current;
                else n->parent->left = current;
            }

            current->right = n->right;
            if(n->right != NULL)
                n->right->parent = current;
            current->left = n->left;
            if(n->left != NULL)
                n->left->parent = current;
        }
    }
    free(n);
    t->count--;
    return 0;
}
```

__Выполнение левого поворота дерева относительно корня:__
```c
void rotate_left(tree* t)
{
    if(t->root == NULL)
        return;
    node *nroot = t->root;
    if(nroot->right == NULL)
        return;
    node *tmp = NULL;
    do
    {
        nroot = t->root;
        tmp = nroot->right;
        t->root = tmp;
        tmp->parent = NULL;
        nroot->parent = tmp;
        nroot->right = tmp->left;
        if (tmp->left != NULL)
            tmp->left->parent = nroot;
        tmp -> left = nroot;
    }while(tmp->right != NULL);
}
```

__Выполнение правого поворота дерева относительно корня:__
```c
void rotate_right(tree* t) {
    if(t->root == NULL)
        return;
    node *nroot = t->root;
    if(nroot->left == NULL)
        return;
    node *tmp = NULL;
    do
    {
        nroot = t->root;
        tmp = nroot->left;
        t->root = tmp;
        tmp->parent = NULL;
        nroot->parent = tmp;
        nroot->left = tmp->right;
        if (tmp->right != NULL)
            tmp->right->parent = nroot;
        tmp -> right = nroot;
    }while (tmp->left != NULL);
}
```
__Обход в глубину:__
```c
int deepness(node * n, int deep){
    if (n == NULL){
        return deep;
    }
    int d1 = deepness(n->left, deep + 1);
    int d2 = deepness(n->right, deep + 1);

    if (d1 > d2)
        return d1;
    else return d2;
}
```

__Вывод всего дерева:__
```c
void printNode(node * n, int level, int deep){

    if (level == deep)
    {
        if (n == NULL){
            printf("_ ");
        }
        else
        {
            printf("%d ", n->value);
        }
    }
    else if (n != NULL)
    {
        printNode(n->left, level + 1, deep);
        printNode(n->right, level + 1, deep);
    }
    else
    {
        printNode(n, level + 1, deep);
        printNode(n, level + 1, deep);
    }
}
void print_tree(tree * t)
{
    if(t->root==NULL)
    {
        printf("-\n\n");
        return;
    }
    node *n = t -> root;
    int m = deepness(n, 0);
    for (int i = 1; i <= m; i++){
        printNode(n, 1, i);
        printf("\n");
    }
    printf("\n");
}
```

__Вывод предка и потомков элемента:__
```c
void print(node * n)
{
    if(n == NULL)
    {
        printf("-");
        printf("\n\n");
        return;
    }
    if(n->parent != NULL)
        printf("%d ",n->parent->value);
    else printf("_ ");
    if(n->left != NULL)
        printf("%d ",n->left->value);
    else printf("_ ");
    if(n->right != NULL)
        printf("%d ",n->right->value);
    else printf("_ ");
    printf("\n\n");
}
```


__Метод main:__
```c
int main() {
    tree *t;
    t = malloc(sizeof(tree));
    init(t);
    int x1,x2,x3,x4;
    (void)scanf("%d %d %d %d", &x1, &x2, &x3, &x4);
    insert(t,x1);
    insert(t,x2);
    insert(t,x3);
    insert(t,x4);
    print_tree(t);

    int y1,y2,y3;
    (void)scanf("%d %d %d", &y1, &y2, &y3);
    insert(t,y1);
    insert(t,y2);
    insert(t,y3);
    print_tree(t);

    int m1;
    (void)scanf("%d", &m1);
    node *M1 = find(t,m1);
    print(M1);

    int m2;
    (void)scanf("%d", &m2);
    node *M2 = find(t,m2);
    print(M2);

    int m3;
    (void)scanf("%d", &m3);
    remove_node(t,m3);
    print_tree(t);

    rotate_left(t);
    print_tree(t);
    rotate_right(t);
    print_tree(t);

    int count = t->count;
    printf("%d\n\n", count);

    node *nroot = t->root;

    clean(t,nroot);
    //free(t);
    print_tree(t);

    return 0;
}
```

На рис. 3 представлен результат тестирования pipeline.

![Результат pipeline](https://sun9-22.userapi.com/impg/xKNXp3ow-no_AWfvreSYPtQ-2OJZpk9dRtVS5w/GetJeSlj5Ao.jpg?size=267x210&quality=96&sign=da0a209ceaffbde20c325fcbeaf9df4a&type=album)
>Рисунок 3 - Результат теста pipeline

---


### __Заключение__
В ходе данной практической работы была решена задача по теме "Бинарные деревья поиска". Реализованы все заданные структуры и функции. Написанная программа успешно прошла все тесты и проверки.
