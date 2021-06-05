# **Отчёт по седьмой практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.


### Задания на практическую работу:

Реализовать программу, которая реализует алгоритмы сортировки:
1. быстрая сортировка;
2. пирамидальная сортировка.

Программа принимает на вход количество элементов и на отдельной строке массив элементов и выводит отсортированный по возрастанию массив.

### Ход работы
---


#### __1 Программа:__

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

__Быстрая сортировка:__
```c
void quickSort(int *numbers, int left, int right)
{
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    pivot = numbers[left];
    while (left < right) // пока границы не сомкнутся
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        if (left != right) // если границы не сомкнулись
        {
            numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу влево
        }
    }
    numbers[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
    if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}
```
__Пирамидальная сортировка:__
```c
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;

}
void heapify(int arr[], int n, int i)
{
    int largest = i;
// Инициализируем наибольший элемент как корень
    int l = 2*i + 1; // левый = 2*i + 1
    int r = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n)
{
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i=n-1; i>=0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}
```

__Метод main:__
```c
int main()
{
    int n;
    (void)scanf("%d",&n);
    int *a = (int*)malloc(sizeof(int) * n);
    for(int i =0; i < n; i++)
    {
        (void)scanf("%d", &a[i]);
    }
    //quickSort(a, 0, n-1); // вызов функции быстрой сортировки
    heapSort(a,n); // ...пирамидальной сортировки

    // Вывод элементов массива после сортировки
    for (int i = 0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
    getchar();
    return 0;
}
```

#### __2 Примеры результатов:__

На рис. 1 и 2 представлены примеры результатов.

![example1](https://sun9-27.userapi.com/impg/Jxv_nigTBkLSpVVSsP3e6gXl4xxDhVByuqQgGA/YnNvEcHg0iA.jpg?size=143x53&quality=96&sign=cb413cc1d037964548e717bd07226527&type=album)
>Рисунок 1 - Пример 1

![example2](https://sun9-6.userapi.com/impg/eJCNau1qSpaewBRpvq2kFyduCVaS68BcyTH0IA/laVd3SDQ_rY.jpg?size=85x52&quality=96&sign=34355eadbf45e20795e0251f3076f328&type=album)
>Рисунок 2 - Пример 2
---

### __Заключение__
В ходе данной практической работы была решена задача по теме "Алгоритмы сортировки". Реализованы все заданные структуры и методы быстрой и пирамидальной сортировок. Написанная программа успешно прошла все тесты и проверки.
