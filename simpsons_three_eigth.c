#include<stdio.h>
#define INTERVALS 999   //intervals must be a multiple of three

double f(double x)
{
    return (x*x)+1; //write your functions here 
}

int main()
{
    double a,b,h;
    printf("Enter range of integration [a,b] as a b\n");
    scanf("%lf %lf",&a,&b);
    h=(b-a)/INTERVALS;

    double sum_not_three=0,sum_three=0;

    for(int i=1;i<INTERVALS;i++)
    {
        if(i%3==0)
        {
            sum_three+=f(a+i*h);
        }
        else
        {
            sum_not_three+=f(a+i*h);
        }
        
    }

    double result=(3*h/8)*(f(a)+f(b)+3*sum_not_three+2*sum_three);
    printf("Output is %lf",result);
    return 0;
}