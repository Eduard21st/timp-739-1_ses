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
