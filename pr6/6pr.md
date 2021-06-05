# **Отчёт по шестой практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.


### Задания на практическую работу:

Реализовать три программы, которые:
1. Считают с входного потока 7 чисел и заносят их в дерево;
2. выводят все значения вершин дерева через пробел в порядке их посещения.

Первая программа должна иметь метод обхода в ширину, вторая - прямого обхода, а третья - обратного обхода.


### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было настроить pipeline в файле .gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-50.userapi.com/impg/7uvJKsoMuRUHG4UM0cHAPeu6_M8gROV1utWc6g/x-gJ0yMiU9E.jpg?size=124x41&quality=96&sign=23ae172c30620a21280184d0816f535b&type=album)
>Рисунок 1 - Добавление пятой работы

![pipeline](https://sun9-17.userapi.com/impg/CUYPFnMWR8t8Or2Wj11Fhzykk6Dl-nhpvMHDIQ/vYv2i8mUow4.jpg?size=307x324&quality=96&sign=b9ed14ce9e63eacd9cf8d18b048fbbfd&type=album)
>Рисунок 2 - Добавление тестов
---

#### __3 Программа №1:__

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

__Вывод элементов, обход:__
```c
void printNode(node * n, int level, int deep){

    if (level == deep)
    {
        if(n != NULL)
            printf("%d ", n->value);
    }
    else
    {
        printNode(n->left, level + 1, deep);
        printNode(n->right, level + 1, deep);
    }
}
void bfs(struct node * n)
{
    int m = deepness(n, 0);
    for (int i = 1; i <= m; i++)
    {
        printNode(n, 1, i);
    }
}
```

__Метод main:__
```c
int main() {
    tree * t = malloc(sizeof(tree));
    init(t);

    for (int i = 0; i < 7; i++)
    {
        int x;
        scanf("%d", &x);
        insert(t, x);
    }
    node *n = t->root;
    bfs(n);
    return 0;
}
```

#### __4 Программа №2:__

В данной программе реализованы те же структуры, методы инициализации, поиска, вставки значения и обхода в глубину

__Прямой обход:__
```c
void pre_order(struct tree * t)
{
    node *tmp[8];
    int z = 0;
    node *current = t->root;
    for(int i = 0; i< t->count; i)
    {
        do
        {
            printf("%d ", current->value);
            if(current -> right != NULL)
            {
                tmp[z] = current->right;
                z++;
            }

            current = current->left;
            i++;
        }while(current != NULL);
        current = tmp[z-1];
        z--;
    }
}
```

__Метод main:__
```c
int main() {
    tree * t = malloc(sizeof(tree));
    init(t);

    for (int i = 0; i < 7; i++){
        int x;
        scanf("%d", &x);
        insert(t, x);
    }
    pre_order(t);
    return 0;
}
```

#### __5 Программа №3:__

В данной программе реализованы те же структуры, методы инициализации, поиска, вставки значения и обхода в глубину

__Обратный обход:__
```c
void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> value);
}
```

__Метод main:__
```c
int main() {
    tree * t = malloc(sizeof(tree));
    init(t);

    for (int i = 0; i < 7; i++){
        int x;
        scanf("%d", &x);
        insert(t, x);
    }
    node *n = t->root;
    postorder(n);
    return 0;
}
```

На рис. 3 представлен результат тестирования pipeline.

![Результат pipeline](https://sun9-26.userapi.com/impg/Pkkm14JCu_MiBSyMXRXsqNI1fPzXXu20lkKiIg/jaP2MrdHI1c.jpg?size=281x255&quality=96&sign=f1c9d4352e1c461f28d57742e5f66532&type=album)
>Рисунок 3 - Результат теста pipeline

---


### __Заключение__
В ходе данной практической работы была решена задача по теме "Обход бинарного дерева поиска". Реализованы все заданные структуры и функции. Написанны три программы, которые успешно прошли все тесты и проверки.
