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
