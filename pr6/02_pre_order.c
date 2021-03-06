#include <stdio.h>
#include <stdlib.h>

// Структура для хранения дерева.
// Хранит ссылку на корень дерева и количество элементов в дереве


// Структура для хранения узла дерева.
// Необходимо хранить ссылки на потомков, предка и некоторое значение
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
// Инициализация дерева
void init(tree* t)
{
    t -> root = NULL;
    t -> count = 0;
}

// Поиск элемента по значению. Вернуть NULL если элемент не найден
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

// Вставка значения в дерево:
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

    while(current!=NULL)
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
        if(last_n != NULL)
        {
            if(current -> value < last_n -> value)
                last_n -> left = current;
            else
                last_n -> right = current;
        }

        if(t->count == 0)
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
