#include<stdio.h>
#define INTERVALS 1000

double f(double x)
{
    return (x*x)+1; //write your function here
}

int main()
{
    double a,b,h;
    printf("Enter the range of integration [a,b] as a b\n");
    scanf("%lf %lf",&a,&b);
    h=(b-a)/INTERVALS;

    double sum_odd=0,sum_even=0;

    for(int i=1;i<INTERVALS;i++)
    {
        if(i%2!=0)
            sum_odd+=f(a+i*h);
        else
        {
            sum_even+=f(a+i*h);
        }
    }

    double result=(h/3)*(f(a)+f(b)+4*sum_odd+2*sum_even);

    printf("Output is %lf",result);
    return 0;

}