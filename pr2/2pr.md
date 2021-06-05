# **Отчёт по второй практической работе ТиМП**
Выполнил: студент гр. 739-1, Семенов Э.С.


### Задания на практическую работу:
__Вариант 12__

__Поиск максимума:__
На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 чисел 𝑥𝑖 ∈ Z : |𝑥𝑖 | ≤ 2147483647 для любого целого 𝑖 от 1 до 𝑛. Вывести значение максимального 𝑥𝑖.

__Баланс скобок:__ На вход подаётся число 𝑛 ∈ N : 𝑛 ≤ 2147483647, а также 𝑛 разделённых пробелом символов 𝑥𝑖 ∈ {︁ (,) }︁ для любого целого 𝑖 от 1 до 𝑛. Вывести 1, если соблюден баланс скобок (т.е. первая скобка должна быть открывающейся, и количество открывающихся и закрывающихся скобок должно совпадать), иначе вывести 0.



### Ход работы
---
#### __1 Настройка pipeline__

Перед началом работы необходимо было натсроить pipeline в файле .gitlab_ci.yml, что представлено на рисунках 1 и 2.

![pipeline](https://sun9-67.userapi.com/impg/KVYHBKYGPz_SBOoCBL7Z89g6fOhqcvg6m5BvyQ/eVBCVtWgLfU.jpg?size=107x54&quality=96&sign=9b22c8a0ec7aa29b692236b099833187&type=album)
>Рисунок 1 - Добавление второй работы

![pipeline](https://sun9-53.userapi.com/impg/AA6RNPrZ8u32or7xNbrb7u7sUEEaVBnkQO7weg/6BO38Uyhij0.jpg?size=306x478&quality=96&sign=4613169da95763f52fa09e2a2c960646&type=album)
>Рисунок 2 - Добавление номеров программ
---
#### __2 Блок-схемы программ__

На рис. 3 представлена блок-схема первой программы.

![1блоксхема](https://sun9-54.userapi.com/impg/52ij43caiY-QtZPzYDp0GIaVp9Kyr4jZGj_vig/vPEjDPyrm48.jpg?size=456x749&quality=96&sign=b048e0add0f1b01c614e5a3366fafc38&type=album)
>Рисунок 3 - Блок-схема 1-й программы

На рис. 4 представлена блок-схема второй программы.

![2блоксхема](https://sun9-23.userapi.com/impg/TPRWIwjDLEHXeWJ6-b8gyiuNLSsvg0PUGPiAuA/4DpJ4IRxRq0.jpg?size=565x811&quality=96&sign=f896f4db77ddc08dbe967b5e893efc8c&type=album)
>Рисунок 4 - Блок-схема 2-й программы

#### __3 Были написаны программы по заданиям:__

__Листинг первой программы и её работа:__
```C
#include <stdio.h>
int main(void)
{
int n,x,max,i;
(void)scanf("%d", &n);
(void)scanf(" %d", &x);
max = x;
for (i = 2; i <= n; i++)
{
(void)scanf(" %d", &x);
if (x > max)
{
max = x;
}
}
printf("%d\n", max);
return 0;
}
```
На рис. 5 представлен результат работы первой программы.

![Результат первой программы](https://sun9-16.userapi.com/impg/7A8x6iP15lULSdgMLaPHEvqYJViEwp0gx5miOA/qUQMOxWeMUM.jpg?size=733x253&quality=96&sign=b28e60d2f70be02ac9da86be5bef1e36&type=album)
>Рисунок 5 - Результат первой программы

__Листинг второй программы и её работа:__
```C
#include <stdio.h>
int main(void)
{
char x;
int left_br = 0, right_br = 0, n, c = 0, i;
(void)scanf("%d", &n);
(void)scanf(" %c", &x);
if (x != '(')
{
printf("%d\n", c);
return 0;
}
else
{
left_br++;
}

for (i = 2; i <= n; i++)
{
(void)scanf(" %c", &x);
if (x == '(')
{
left_br++;
}
else if (x == ')')
{
right_br++;
}
else
{
printf("%d\n", c);
return 0;
}
}
if (left_br == right_br)
{
c = 1;
}
printf("%d\n", c);
return 0;
}
```
На рис. 6 представлен результат работы данной программы.

![Результат второй программа](https://sun9-56.userapi.com/impg/ZxDNTA3ldFbLt2Y9_KlxDlNb44StbtEMwEoCLg/hMF_WV9BIcU.jpg?size=737x398&quality=96&sign=670d1cb1177b49a94202109f733cd68c&type=album)
>Рисунок 6 - Результат второй программы

---


### __Заключение__
В ходе данной практической работы были решены две задачи по теме "Однопроходные алгоритмы". Были составлены блок-схемы для этих задач и написаны программы, которые успешно прошли все тесты и проверки.
