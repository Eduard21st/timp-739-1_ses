# **Отчёт по первой практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.

#### Задания на практическую работу:
__Программа 01__
Написать программу, печатающую в stdout фразу "Hello, World!" на отдельной строке.

__Программа 02__
Написать программу, принимающую на вход два числа, разделённые пробелом, и суммирующую их. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647.

__Программа 03__
Написать программу, принимающую на вход числа x и y, разделённые пробелом, и вычисляющую x в степени y. Ввод чисел производить из stdin, вывод результата - в stdout. Вводимые числа не превосходят по модулю 2147483647. Реализовывать возведение в степень через цикл/рекурсию не допускается.

#### Ход работы
Были установлены все требуемые для работы программы, что видно на рис.1.

![photo1](https://sun9-22.userapi.com/impg/EOkbiqI8UXIdwp07ZhqziLb9FKgQ3JKFGAjweg/HPOTeVHFvYA.jpg?size=740x327&quality=96&sign=f7b87d3637ed5faef6032ffb86200b54&type=album)
>Рисунок 1 - Успешная установка требуемых программ

---
### __Были написаны программы по заданиям:__

__Листинг первой программы и её работа:__
```C
#include <stdio.h>
int main()
{
printf("Hello, World!");
return 0;
}
```
На рис. 2 представлен результат работы первой программы

![Результат первой программы](https://sun9-26.userapi.com/impg/xA0XoWnoB8YnTRkyQL7j94GQfXBcNy7q9_9BxQ/P55G9sJGw3s.jpg?size=740x180&quality=96&sign=dc146c23ad08d093ab78e6d3894f6027&type=album)
>Рисунок 2 - Результат первой программы

__Листинг второй программы и её работа:__
```C
#include <stdio.h>
int main(void)
{
double x,y,c;
if ((scanf("%lf", &x)==1)&&(scanf("%lf", &y)==1))
{
c = x+y;
printf("%lf\n", c);
}
return 0;
}
```
На рис. 3 представлен результат работы данной программы

![Результат второй программа](https://sun9-49.userapi.com/impg/VZVXnXqKGutlalXyp6BetaA7y1F99P99gT7MCw/KxrHAute5zc.jpg?size=741x219&quality=96&sign=6216e91c7506702fd604077454bd231c&type=album)
>Рисунок 3 - Результат второй программы

__Листинг третьей программы и её работа:__
```C
#include <stdio.h>
#include <math.h>
int main()
{
double x,y;
if ((scanf("%lf", &x)==1)&&(scanf("%lf", &y)==1))
{
double c = pow(x,y);
printf("%lf\n", c);
}
return 0;
}
```
На рис. 4 представлен результат работы программы

![Результат третей программа](https://sun9-37.userapi.com/impg/H73JAeYW4HBUE4z8tMDa_8vnlhDRrh1dMw1qWQ/ZLwFmaPn9Z8.jpg?size=738x223&quality=96&sign=13a9e41004b70eb5e17401ff8f9ae969&type=album)
>Рисунок 4 - Результат третей программы

---

### __Таблица результатов [программ](https://gitlab.com/Eduard21st/practices/-/tree/master/pr1)__

| | Программа 1 | Программа 2 | Программа 3
:---| :---: | :---: | :---:
a | - | 100 | 12
b | - | 152 | 3
Результат| Hello, World!| 252 | 1728

### __Заключение__
В ходе данной практической работы были получены навыки работы с системой контроля версий git и языком программирования Си. Также были успешно написаны три программы, которые успешно прошли все тесты и проверки.
