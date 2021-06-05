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
