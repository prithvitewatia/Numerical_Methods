#include<stdio.h>
#define INTERVALS 1000

double f(double x)
{
    return (x*x)+1; //write your function here
}

int main()
{
    double a,b,h;
    printf("enter range of integration [a,b] as a b\n");
    scanf("%lf %lf",&a,&b);
    h=(b-a)/INTERVALS;

    double sum_terms=0;

    for(int i=1;i<INTERVALS;i++)
    {
        sum_terms+=f(a+i*h);
    }
    double result=h*((f(a)+f(b))/2 +sum_terms);
    printf("OUTPUT is %lf",result);
    return 0;
}